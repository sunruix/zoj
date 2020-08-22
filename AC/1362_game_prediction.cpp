#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int m, n, i, j, k, a[1024], ans, count = 1;

	while (scanf("%d %d", &m, &n) != EOF && (m || n)) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), comp);
		i = k = ans = 0, j = m * n;
		while (i < n) {
			while (a[i] < j)
				j--, k--;
			while (i < n - 1 && a[i] - a[i + 1] == 1)
				i++, k++, j--;
			i++, k++, j--;
			if (k > 0)
				ans += k, k = 0;
		}
		printf("Case %d: %d\n", count++, ans);
	}
	return 0;
}

