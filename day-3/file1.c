#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int pid;

    pid = fork();

    if (pid == 0)
    {
        if (execl("./file2.exe", argv[1], argv[2], (char *)NULL) < 0)
            perror("error");
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("\nParent(PID=%d) : Done \n", getpid());
    }

    exit(0);
}
