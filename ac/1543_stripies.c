#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int n, i, a[128];
	double ans;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), comp);
		for (ans = a[0], i = 1; i < n; i++)
			ans = 2.0 * sqrt(ans * a[i]);
		printf("%.3f\n", ans);
	}
	return 0;
}