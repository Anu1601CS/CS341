// Name: Anurag
// Roll n0 : 1601CS05

#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int m, l, p;

	printf("Enter the  Main memory(GB), Virtual Address Space(GB) and Page size(kB):\n");
	scanf("%d %d %d", &m, &l, &p);

	printf("1)Number of pages = L/P: %f\n", 1024.0 * 1024.0 * (float)l / (float)p);
	printf("2)Number of frames = M/P: %f\n", 1024.0 * 1024.0 * (float)m / (float)p);

	printf("3)Number of bits required to represent the physical address space: %f\n", log(1024.0 * 1024.0 * 1024.0 * m) / log(2) + 1);
	printf("4)Number of bits required to represent the virtual address space: %f\n", log(1024.0 * 1024.0 * 1024.0 * l) / log(2) + 1);
	printf("5)Number of bits required to represent the page offset: %f\n", log(1024 * p) / log(2) + 1);

	printf("6)Page table size is(in mB): %f\n", 4 * (float)l / (float)p);

	return 0;
}
