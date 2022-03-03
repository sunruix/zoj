#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int N, A[128], B[128], i, j, k;
	while (scanf("%d", &N) != EOF && N) {
		for (i = 0; i < N; i++)
			scanf("%d", &A[i]);
		qsort(A, N, sizeof(int), comp);
		B[0] = A[0];
		for (i = 1, j = 1; i < N; i++)
			if (A[i] != B[j - 1])
				B[j++] = A[i];
		for (i = 0; i < j - 1; i++)
			printf("%d ", B[i]);
		printf("%d\n", B[i]);
	}
	return 0;
}
