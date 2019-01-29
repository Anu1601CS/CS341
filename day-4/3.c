#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define NUM_THREADS 4

void *Busy(void *t)
{
    long tid;
    tid = (long)t;

    printf("Busy thread id: %ld \n", tid);
    sleep(3);
    pthread_exit((void *)t);
}

int main(int argc, char *argv[])
{
    pthread_t thread[NUM_THREADS];
    //Declare a pthread attribute variable of the pthread_attr_t data type
    pthread_attr_t attr;
    int err1, err2;
    long t;
    void *status;

    //Initialize the attribute variable with pthread_attr_init()
    pthread_attr_init(&attr);
    // Set the attribute detached status with pthread_attr_setdetachstate()
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("Creating thread %ld\n", t);
        err1 = pthread_create(&thread[t], &attr, Busy, (void *)t);
        if (err1)
        {
            printf("ERROR; return code from pthread_create() is %d\n", err1);
            exit(-1);
        }
        else
        {
            printf("ERROR; return code from pthread_create() is %d\n", err1);
        }

        err2 = pthread_join(thread[t], &status);
        if (err2)
        {
            printf("ERROR; return code from pthread_join() is %d\n", err2);
            exit(-1);
        }
        else
        {
            printf("ERROR; return code from pthread_join() is %d\n", err2);
        }
        printf("Completed join with thread %ld having a status of %ld\n\n", t, (long)status);
    }

    printf("Exiting from program.\n");
    pthread_exit(NULL);
}
