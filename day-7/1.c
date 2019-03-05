// Name: Anurag
// Roll no: 1601CS05

#include <stdio.h>
#include <stdlib.h>

int globalBss;

int textFun()
{
    return 1;
}

int main(void)
{
    int data;
    static int bss;
    char *headSection = malloc(sizeof(char) * 10);

    printf("Addresses of text section:\t%p\n",(void*)&textFun);
    printf("Addresses of bss section:\t%p\n",(void*)&globalBss);
    printf("Addresses of heap section:\t%p\n",(void*)&headSection);
    printf("Addresses of stack section:\t%p\n",(void*)&data);

    return 0;
}
