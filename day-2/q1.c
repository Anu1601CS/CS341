// Name: Anurag
// Roll no: 1601CS05

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid;

    // Variable pid will store the value returned from fork() system call
    pid = fork();

    // If fork() returns zero then it means it is child process.
    if (pid == 0)
    {
        // This is first child process getpid() gives the process
        // id and getppid() gives the parent id of that process.
        printf("Child: pid = %d and ppid = %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent: pid = %d and ppid = %d\n", getpid(), getppid());
    }

    return 0;
}
