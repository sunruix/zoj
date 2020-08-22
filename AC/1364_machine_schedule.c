#include <stdio.h>
#include <string.h>

int dfs(int v, int n, int m, int g[256][256], int *vis, int *mat)
{
	int w;

	for (w = n + 1; w <= n + m; w++)
		if (g[v][w] && !vis[w]) {
			vis[w] = 1;
			if (!mat[w] || dfs(mat[w], n, m, g, vis, mat)) {
				mat[w] = v;
				return 1;
			}
		}
	return 0;
}

int main()
{
	int n, m, i, j, k, a, g[256][256], vis[256], mat[256], ans;

	while (scanf("%d %d %d", &n, &m, &k) != EOF && n) {
		memset(g, 0, sizeof(g)), memset(mat, 0, sizeof(mat));
		while (k--) {
			scanf("%d %d %d", &a, &i, &j);
			if (i && j)
				g[i][j + n + 1] = 1;
		}
		for (ans = 0, i = 1; i <= n; i++)
			memset(vis, 0, sizeof(vis)), ans += dfs(i, n, m, g, vis, mat);
		printf("%d\n", ans);
	}
	return 0;
}