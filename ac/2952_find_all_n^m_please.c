#include <stdio.h>
#include <stdlib.h>
#define max 0x7fffffff

int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i, j, n, ans[65536];

	for (n = 0, i = 2; max / i >= i; i++)
		for (j = i; max / j >= i; n++)
			ans[n] = (j *= i);
	qsort(ans, n, sizeof(int), comp);
	printf("%d\n", ans[0]);
	for (j = ans[0], i = 1; i < n; i++)
		if (j != ans[i])
			printf("%d\n", ans[i]), j = ans[i];
	return 0;
}
