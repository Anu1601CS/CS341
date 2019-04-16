// Name: Anurag
// Roll no : 1601CS05

#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int M, N, L, n;

	printf("Enter M(bits), N(kB), L, n:\n");
	scanf("%d %d %d %d", &M, &N, &L, &n);

	int answer = M - log(1024.0 * N) / log(2.0) - (log(L) / log(2.0) - log(n) / log(2));

	printf("Minimum size of tag: %d\n", answer);
	return 0;
}
