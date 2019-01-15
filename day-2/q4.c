// Name: Anurag
// Roll no: 1601CS05

// Headers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // Declear variables
    int t = 0;
    int pid;

    // Read sleep time t
    printf("Enter sleep time t: ");
    scanf("%d", &t);
    printf("\n");

    // fork the process
    pid = fork();

    // If fork() returns zero then it means it is child process.
    if (pid == 0)
    {
        // Child process
        printf("\nChild: pid = %d\n", getpid());
        printf("Starting the child process.\n");
        printf("\nChild: List of system process:\n");
        // System function to print list of process.
        system("ps");
        // Make the sleep
        sleep(t);
        printf("Exiting the child process. (Die)\n");
        exit(0);
    }
    else
    {
        // Parent process
        printf("Waiting for child process to die.\n");

        // Wait function to wait child process to terminate.
        wait(NULL);
        printf("\nParent: List of system process:\n");

        // System function to print list of process.
        system("ps");
        printf("\nParent: pid = %d\n", getpid());
        printf("\nExiting the parent process. (Die)\n");
        exit(0);
    }

    return 0;
}
