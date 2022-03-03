#include <stdio.h>
#include <string.h>

int dfs(int i, int n, int g[][128], int vis[])
{
	int j;

	for (vis[i] = 1, j = 1; j <= n; j++)
		if (g[i][j] && i != j)
			if (vis[j] || !dfs(j, n, g, vis))
				return 0;
	vis[i] = 0;
	return 1;
}

int main()
{
	int n, i, k, v, w, e, g[128][128], vis[128];

	while (scanf("%d", &n) != EOF && n > 0) {
		memset(g, 0, sizeof(g)), memset(vis, 0, sizeof(vis));
		for (k = i = 0; i < n; i++) {
			scanf("%d %d", &v, &w), g[v][w] = 1;
			k = k > v ? k : v;
			k = k > w ? k : w;
		}
		scanf("%d", &e);
		printf("%s\n", dfs(e, k, g, vis) ? "Yes" : "No");
	}
	return 0;
}