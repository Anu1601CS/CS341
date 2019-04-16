// Name: Anurag
// Roll no : 1601CS05

#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	float s, a, h;

	printf("Enter search time(ms), access time(ms), hit ratio(0 < h < 1):\n");
	scanf("%f %f %f", &s, &a, &h);

	printf("Effective memory access time is: %f ms\n", h * s + (1 - h) * (s + a));
	return 0;
}
