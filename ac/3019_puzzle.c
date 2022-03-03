#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int m, n, i, j, a[10000], b[10000], count;
	while (scanf("%d %d", &m, &n) != EOF) {
		for (i = 0; i < m; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &b[i]);
		qsort(a, m, sizeof(int), comp);
		qsort(b, n, sizeof(int), comp);
		for (i = j = 0, count = 0; i < m && j < n;) {
			if (a[i] < b[j])
				i++;
			else if (a[i] > b[j])
				j++;
			else
				count++, i++, j++;
		}
		printf("%d\n", count);
	}
	return 0;
}

