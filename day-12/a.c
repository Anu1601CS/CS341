// Name- ANURAG
// Roll No.- 1601CS05

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <pthread.h>
#include <unistd.h>
#define sem1 "/semaphore3"
#define sem2 "/semaphore4"
#include <sys/mman.h>
#include <fcntl.h>
#define MAX 10

int *rCount;
int *data;
pid_t readerA, readerB;
sem_t *mutex, *wBlock;

void writer(pid_t readerA, pid_t readerB)
{
    sem_wait(wBlock);

    FILE *fptr;
    fptr = fopen("buffer.txt", "r");
    fscanf(fptr, "%d", data);
    fclose(fptr);

    if ((*data) + 1 == MAX)
    {
        kill(readerA, SIGKILL);
        kill(readerB, SIGKILL);

        sem_close(sem1);
        sem_close(sem2);

        printf("Writer enters.\nWriter leaves because the MAX value is reached and written to shared file.\n");

        *data = 0;
        fptr = fopen("buffer.txt", "w");
        fprintf(fptr, "%d", (*data));
        fclose(fptr);
        exit(0);
    }
    else
    {
        fptr = fopen("buffer.txt", "w");
        fprintf(fptr, "%d", (*data) + 1);
        fclose(fptr);
    }

    printf("Writer enters.\nWriter(%d) writes the value %d\nWriter leaves.\n", getpid(), (*data) + 1);

    sem_post(wBlock);
    sleep(2);
}

void reader()
{
    sem_wait(mutex);
    *rCount = (*rCount) + 1;

    if (*rCount == 1)
    {
        sem_wait(wBlock);
        printf("First reader enter.\n");
    }

    sem_post(mutex);
    FILE *fptr;

    fptr = fopen("buffer.txt", "r");
    fscanf(fptr, "%d", data);
    fclose(fptr);

    printf("Reader(%d) reads the value %d.\n", getpid(), *data);

    sleep(2);
    sem_wait(mutex);

    *rCount = (*rCount) - 1;

    if (*rCount == 0)
    {
        sem_post(wBlock);
        printf("Last reader leave.\n");
    }

    sem_post(mutex);
    sleep(2);
}

int main()
{
    rCount = mmap(NULL, sizeof(*rCount), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    data = mmap(NULL, sizeof(*data), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *data = -1;

    if (*data == -1)
    {
        printf("File created. VAR is 0.\n");
        *data = 0;
        *rCount = 0;

        mutex = sem_open(sem1, O_CREAT, 0644, 1);
        wBlock = sem_open(sem2, O_CREAT, 0644, 1);
    }

    readerA = fork();

    if (readerA == 0)
    {
        do
        {
            reader();
        } while (1);
    }
    else
    {
        readerB = fork();

        if (readerB == 0)
        {
            do
            {
                reader();
            } while (1);
        }
        else
        {
            do
            {
                writer(readerA, readerB);
            } while (1);
        }
    }

    return 0;
}
