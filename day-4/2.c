#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

int globalVar = 0;

void *createThread(void *threadid)
{
    static int staticVar = 0;
    int localVar = 0;
    int *tid;
    tid = (int *)threadid;

    ++staticVar;
    ++globalVar;
    ++localVar;

    printf("\nCSE OS LAB, by Thread ID: %d\n", *tid);
    printf("Global:\t%d \n Local:\t%d \nStatic:\t%d \n", globalVar, localVar, staticVar);
    pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
    printf("Intial \nGlobal:\t%d \nLocal:\t%d \nStatic:\t%d \n", 0, 0, 0);

    pthread_t threads[NUM_THREADS];

    int rc, t, tids[NUM_THREADS];

    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("\nCreating thread %d\n", t);
        tids[t] = t;
        rc = pthread_create(&threads[t], NULL, createThread, (void *)&tids[t]);

        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}
