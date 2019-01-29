#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *func(void *threadid)
{
    int i;

    for (i = 2; i <= 100; i = i + 2)
        printf("%d\n", i);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads;

    int a;
    int t, tids = 1;

    pthread_create(&threads, NULL, func, (void *)&tids);

    for (a = 1; a <= 100; a = a + 2)
        printf("%d\n", a);

    pthread_exit(NULL);
}
