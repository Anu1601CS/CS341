#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int a;
    int b;
    int res = 0;

    a = atoi(argv[0]);
    b = atoi(argv[1]);

    if (*argv[2] == '+')
        res = a + b;
    else
        res = a - b;

    printf("\nResult from server: % d\n", res);

    return res;
}
