#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int fac(int n)
{
    if (n >= 1)
        return n * fac(n - 1);
    else
        return 1;
}

int main(int argc, char **argv)
{
    int i;
    int n;
    float a;
    double res = 0;

    sscanf(argv[0], "%f", &a);
    n = atoi(argv[1]);

    double temp;

    for (i = 1; i <= n; i++)
    {
        temp = pow(a, i);
        temp /= fac(i);
        res += temp;
    }

    printf("Child(PID= %d): For x = %f the first %d terms yeilds %f ", getpid(), a, n, res);

    exit(0);
}
