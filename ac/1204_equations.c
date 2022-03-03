#include <stdio.h>
#include <stdlib.h>

int n, m, a[32], path[32];

int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int dfs(int s, int val, int l, int ll)
{
	int i, *p, flag = 0;
	if (!ll) {
		if (p = bsearch(&val, a, m, sizeof(int), comp)) {
			for (i = 0; i < l - 1; i++)
				printf("%d+", a[path[i]]);
			printf("%d=%d\n", a[path[i]], val);
			return 1;
		}
		return 0;
	}
	path[l - ll] = s;
	for (i = s + 1; i <= m - ll + 1; i++) {
		if (val + a[s] > a[m - 1])
			break;
		if (ll == 1 && (val + a[s] < a[i] || flag))
			break;
		if (dfs(i, val + a[s], l, ll - 1) && !flag)
			flag = 1;
	}
	return flag;
}

int main()
{
	int i, l, flag;

	scanf("%d", &n);
	while (n--) {
		flag = 0;
		scanf("%d", &m);
		for (i = 0; i < m; i++)
			scanf("%d", &a[i]);
		qsort(a, m, sizeof(int), comp);
		for (l = 2; l <= m - 1; l++)
			for (i = 0; i <= m - l; i++)
				if (dfs(i, 0, l, l) && !flag)
					flag = 1;
		if (!flag)
			printf("Can't find any equations.\n");
		printf("\n");
	}
	return 0;
}
