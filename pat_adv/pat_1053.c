#include <stdio.h>
#include <stdlib.h>

int n, m, s, i, j, k, g[100][100], path[100], ans[100][100], *p[100], w[100], num;

int comp(const void *a, const void *b)
{
	int *pa = *(int *)a, *pb = *(int *)b;

	for (pa++, pb++; *pa == *pb; pa++, pb++);
	return *pa < *pb ? 1 : -1;
}

void search(int r, int l, int left)
{
	int i;

	if (w[r] > left)
		return;
	else if (w[r] == left && !g[r][0]) {
		for (i = 0; i < l; i++)
			ans[num][i] = path[i];
		ans[num][i] = w[r];
		p[num] = ans[num++];
		return;
	}
	for (path[l++] = w[r], i = 1; i <= g[r][0]; i++)
		search(g[r][i], l, left - w[r]);
}

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for (i = 0; i < n; i++)
		scanf("%d", &w[i]);
	for (i = 0; i < m; i++) {
		scanf("%d", &j), scanf("%d", &g[j][0]);
		for (k = 1; k <= g[j][0]; k++)
			scanf("%d", &g[j][k]);
	}
	search(0, 0, s);
	qsort(p, num, sizeof(int *), comp);
	for (i = 0; i < num; i++) {
		for (printf("%d", w[0]), j = 1; p[i][j]; j++)
			printf(" %d", p[i][j]);
		printf("\n");
	}
	return 0;
}