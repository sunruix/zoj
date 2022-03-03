#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int n, i, j, k, a[1024], left, ans, flag;

	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), comp);
		for (i = 0, flag = 0; i < n && !flag; i++)
			for (j = 0; j < n && !flag; j++) {
				if (j == i)
					continue;
				for (k = 0; k < n; k++) {
					if (k == j || k == i)
						continue;
					left = a[i] - a[j] - a[k];
					if (left == a[i] || left == a[j] || left == a[k])
						continue;
					if (bsearch(&left, a, n, sizeof(int), comp)) {
						flag = 1, ans = a[i];
						break;
					}
				}
			}
		if (flag)
			printf("%d\n", ans);
		else
			printf("no solution\n");
	}
	return 0;
}
