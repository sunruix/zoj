#include <stdio.h>

int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int N, IP, save, a[512], i;
	while (scanf("%d %d", &N, &IP) != EOF) {
		for (i = 0; i < N; i++)
			scanf("%d", &a[i]);
		qsort(a, N, sizeof(int), comp);
		for (i = 0, save = 0; i < N; i++) {
			if (IP < a[i]) 
				IP += 2;
			else
				save++;
		}
		printf("%d\n", IP + save);
	}
	return 0;
}
