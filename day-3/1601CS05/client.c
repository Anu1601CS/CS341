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
    int pid;
    char a[1000], b[1000];
    char sign[10];
    int status;

    printf(">");
    scanf("%s %s %s", a, sign, b);

    if (execl("./EXEC", a, b, sign, (char *)NULL) < 0)
        perror("error");

    exit(0);
}
