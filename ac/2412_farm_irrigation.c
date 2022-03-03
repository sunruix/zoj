#include <stdio.h>
#include <string.h>

typedef struct {
	char l, u, r, d;
} node;

node a[16] = {{1, 1, 0, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}, {0, 0, 1, 1},
	{0, 1, 0, 1}, {1, 0, 1, 0}, {1, 1, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 1},
	{0, 1, 1, 1}, {1, 1, 1, 1}};

void dfs(char g[][64], int vis[][64], int m, int n, int i, int j)
{
	int k;

	vis[i][j] = 1;
	if ((k = i - 1) >= 0 && !vis[k][j] && a[g[k][j] - 'A'].d && a[g[i][j] - 'A'].u)
		dfs(g, vis, m, n, k, j);
	if ((k = i + 1) < m && !vis[k][j] && a[g[k][j] - 'A'].u && a[g[i][j] - 'A'].d)
		dfs(g, vis, m, n, k, j);
	if ((k = j - 1) >= 0 && !vis[i][k] && a[g[i][k] - 'A'].r && a[g[i][j] - 'A'].l)
		dfs(g, vis, m, n, i, k);
	if ((k = j + 1) < n && !vis[i][k] && a[g[i][k] - 'A'].l && a[g[i][j] - 'A'].r)
		dfs(g, vis, m, n, i, k);
}

int main()
{
	int n, m, i, j, vis[64][64], ans;
	char g[64][64];

	while (scanf("%d %d\n", &m, &n) != EOF && m > 0) {
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++)
				g[i][j] = getchar();
			getchar();
		}
		ans = 0, memset(vis, 0, sizeof(vis));
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if (!vis[i][j])
					ans++, dfs(g, vis, m, n, i, j);
		printf("%d\n", ans);
	}
	return 0;
}