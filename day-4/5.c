#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void *creatThread(void *arg)
{
    int *val = (int *)arg;
    // sem_wait() decrements (locks) the semaphore pointed to by sem. Wait.
    sem_wait(&mutex);

    *val += 1;

    printf("%d\n", *val);

    // To release a signal
    sem_post(&mutex);
}

int main()
{
    // sem_init - initialize an unnamed semaphore &&  mutex (mutual exclusion object) is a program object that is created so that multiple program thread can take turns.
    sem_init(&mutex, 0, 1);
    pthread_t t1;
    int i = 1;
    int j = 1;

    for (j = 1; j <= 1000; j++)
    {
        printf("%d \n", j);

        pthread_create(&t1, NULL, creatThread, &j);
        pthread_join(t1, NULL);

        sem_init(&mutex, 0, 1);
    }

    sem_destroy(&mutex);

    pthread_exit(NULL);
    return 0;
}
