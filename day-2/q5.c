// Name: Anurag
// Roll no: 1601CS05

// Headers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // System call to this command
    system("cat pipe1.txt | sed 's/peeps/pipes/' pipe1.txt > pipenew.txt");
    return 0;
}
