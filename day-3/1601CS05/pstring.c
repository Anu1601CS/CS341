#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    char buf[100] = "./dstring";

    execlp("/usr/bin/xterm", "xterm", "-hold", "-e", "./dstring", NULL);
    wait(NULL);
}
