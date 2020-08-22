#include <stdio.h>
#include <string.h>

int dfs(int v, int m, char g[][128], char *vis, char *mat)
{
	int w;

	for (w = 1; w <= m; w++)
		if (g[v][w] > 0 && !vis[w]) {
			vis[w] = 1;
			if (!mat[w] || dfs(mat[w], m, g, vis, mat)) {
				mat[w] = v;
				return 1;
			}
		}
	return 0;
}

int main()
{
	int t, n, m, i, j, k, ans, ans1;
	char c, g[128][128], vis[128], mat[128], mat1[128];

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d\n", &n, &m);
		memset(g, 0, sizeof(g)), memset(mat, 0, sizeof(mat));
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++)
				getchar() == '*' ? g[i][j] = 1 : 0;
			getchar();
		}
		for (ans = 0, i = 1; i <= n; i++)
			memset(vis, 0, sizeof(vis)), ans += dfs(i, m, g, vis, mat);
		printf("%d\n", ans);
		for (j = 1; j <= m; j++)
			if (mat[j]) {
				for (i = 1; i <= n; i++)
					g[i][j] = -g[i][j];
				memset(mat1, 0, sizeof(mat1));
				for (ans1 = 0, i = 1; i <= n; i++)
					memset(vis, 0, sizeof(vis)), ans1 += dfs(i, m, g, vis, mat1);
				if (ans1 < ans)
					printf("%d %d\n", 2, j);
				else
					printf("%d %d\n", 1, mat[j]);
				for (i = 1; i <= n; i++)
					g[i][j] = -g[i][j];
			}
		if (t)
			printf("\n");
	}
	return 0;
}