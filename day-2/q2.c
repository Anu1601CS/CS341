// Name: Anurag
// Roll no: 1601CS05

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Factorial function
int fact(int n)
{
    if (n == 1)
        return 1;
    return fact(n - 1) * n;
}

int main()
{
    int pid;
    int n, i, a1, a2;

    printf("Enter an n: ");
    scanf("%d", &n);

    printf("Before Parent --> pid = %d\n", getpid());

    a1 = fact(n);
    pid = fork();
    a2 = fact(n);

    if (pid == 0)
    {
        // This is first child process getpid() gives the process
        // id and getppid() gives the parent id of that process.
        printf("After Child --> pid = %d and factorial = %d\n", getpid(), a1);
    }
    else
    {
        // parent process
        printf("After Parent --> pid = %d and factorial = %d\n", getpid(), a1);
    }

    return 0;
}
