// Name: Anurag
// Roll no: 1601CS05

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid;
    int pipefds[2];
    int returnstatus;
    char writemessages[2][50] = {"Hi, my name is Anurag."};
    char readmessage[50];
    returnstatus = pipe(pipefds);

    if (returnstatus == -1)
    {
        printf("Unable to create pipe\n");
        return 1;
    }

    // Variable pid will store the value returned from fork() system call
    pid = fork();

    // If fork() returns zero then it means it is child process.
    if (pid == 0)
    {
        printf("\nStarted child processs. \n");
        read(pipefds[0], readmessage, sizeof(readmessage));
        printf("Reading from pipe ===> \" %s \"  \n", readmessage);
    }
    else
    {
        printf("\nStarting parent process. \n");
        printf("Writing to pipe ===> \" %s \"  \n", writemessages[0]);
        write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
    }

    return 0;
}
