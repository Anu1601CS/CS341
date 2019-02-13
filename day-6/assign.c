// Name: Anurag
// Roll No: 1601CS05

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t *producers;
pthread_t *consumers;

sem_t buf_mutex, empty_count, fill_count;
int *buf, buffer_pos = -1, pcount, counter, buffer_len;

int produce(pthread_t self)
{
    int i = 0;
    int p = 1 + rand() % 40;

    while (!pthread_equal(*(producers + i), self) && i < pcount)
        i++;

    printf("Producer %d produced %d \n", i + 1, p);

    return p;
}

void consume(int p, pthread_t self)
{
    int i = 0;
    while (!pthread_equal(*(consumers + i), self) && i < counter)
        i++;
    int j = i + 1;

    printf("Buffer:");

    for (i = 0; i <= buffer_pos; ++i)
        printf("%d ", *(buf + i));

    printf("\nConsumer %d consumed %d \nCurrent buffer len : %d\n", j, p, buffer_pos);
}

void *producer(void *args)
{
    while (1)
    {
        sem_wait(&empty_count);
        sem_wait(&buf_mutex);

        int p = produce(pthread_self());
        ++buffer_pos;

        *(buf + buffer_pos) = p;

        sem_post(&buf_mutex);
        sem_post(&fill_count);
        sleep(1 + rand() % 3);
    }

    return NULL;
}

void *consumer(void *args)
{
    int c;
    while (1)
    {
        sem_wait(&fill_count);
        sem_wait(&buf_mutex);

        c = *(buf + buffer_pos);

        consume(c, pthread_self());

        --buffer_pos;

        sem_post(&buf_mutex);
        sem_post(&empty_count);
        sleep(1 + rand() % 5);
    }

    return NULL;
}

int main(void)
{

    int i, err;

    srand(time(NULL));

    sem_init(&buf_mutex, 0, 1);
    sem_init(&fill_count, 0, 0);

    printf("Enter the number of Producers to create :");
    scanf("%d", &pcount);
    producers = (pthread_t *)malloc(pcount * sizeof(pthread_t));

    printf("Enter the number of Consumers to create :");
    scanf("%d", &counter);
    consumers = (pthread_t *)malloc(counter * sizeof(pthread_t));

    printf("Enter buffer capacity you want :");
    scanf("%d", &buffer_len);
    buf = (int *)malloc(buffer_len * sizeof(int));

    int tim;
    printf("How long to sleep before terminating :");
    scanf("%d", &tim);

    sem_init(&empty_count, 0, buffer_len);

    for (i = 0; i < pcount; i++)
    {
        err = pthread_create(producers + i, NULL, &producer, NULL);

        if (err != 0)
            printf("Error creating producer %d: %s\n", i + 1, strerror(err));
        else
            printf("Successfully created producer %d\n", i + 1);
    }

    for (i = 0; i < counter; i++)
    {
        err = pthread_create(consumers + i, NULL, &consumer, NULL);

        if (err != 0)
            printf("Error creating consumer %d: %s\n", i + 1, strerror(err));
        else
            printf("Successfully created consumer %d\n", i + 1);
    }

    sleep(tim);

    for (int i = 0; i < pcount; i++)
        pthread_cancel(producers[i]);

    for (int i = 0; i < counter; i++)
        pthread_cancel(*consumers + i);

    return 0;
}
