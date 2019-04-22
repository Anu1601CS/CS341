#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void fun(int arr[], int l, int r)
{
    int status;
    if (r - l < 2)
    {
        int max = -1;
        int i;

        for (i = l; i <= r; i++)
            if (arr[i] > max)
                max = arr[i];

        printf("PID = %d \t parent PID = %d \t max = %d\n", getpid(), getppid(), max);
        exit(max);
    }
    else
    {
        int cpid1, cpid2;
        if ((cpid1 = fork()) == 0) // Left
        {
            r = (l + r) / 2;
            fun(arr, l, r);
        }
        else if ((cpid2 = fork()) == 0) // Right
        {
            l = (l + r) / 2 + 1;
            fun(arr, l, r);
        }
        else // Parent
        {
            waitpid(cpid1, &status, 0);
            int max1 = status >> 8;

            waitpid(cpid2, &status, 0);
            int max2 = status >> 8;

            int max = max1 > max2 ? max1 : max2;
            printf("PID = %d \t parent PID = %d \t max = %d\n", getpid(), getppid(), max);
            exit(max);
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int arr[110];
    int n, i, status;

    n = 40;

    int cpid;

    //Generate random numbers
    for (i = 0; i < n; i++)
        arr[i] = rand() % 128;

    printf("Original array is : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n");

    if ((cpid = fork()) == 0) // Create Child process
        fun(arr, 0, n - 1);
    else //Create Parent process
    {
        waitpid(cpid, &status, 0);

        int max = status >> 8;
        printf("The maximum value in the array is : %d\n", max);
    }
    sleep(20);
    exit(0);
}
