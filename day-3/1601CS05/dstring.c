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

    FILE *fptr =fopen("process.txt", "r");

    char inp[100];

    int c = 0;

    while(fgets(inp, 100, fptr)!= NULL ) {
        c++;
        if(c % 3 == 0){
            printf("%s\n", inp);
        }
    }

    fclose(fptr);
    wait(NULL);
}
