// Name: Anurag
// Roll no: 1601CS05

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Global Variable
int globalX = 0;

int main()
{
    int pid;

    printf("Before fork value of global : %d\n", globalX);
    // Variable pid will store the value returned from fork() system call
    pid = fork();

    // If fork() returns zero then it means it is child process.
    if (pid == 0)
    {
        // Child process
        globalX = globalX + 3;
        printf("After fork value of global : %d\n", globalX);
        printf("Child: pid = %d\n", getpid());
    }
    else
    {
        // Parent process
        globalX = globalX + 4;
        printf("After fork value of global : %d\n", globalX);
        printf("Parent: pid = %d\n", getpid());
    }

    return 0;
}
