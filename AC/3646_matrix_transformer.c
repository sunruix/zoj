#include <stdio.h>
#include <string.h>

int dfs(int v, int n, char g[256][256], char *vis, int *m)
{
	int w;

	for (w = 0; w < n; w++)
		if (g[v][w] == 'U' && !vis[w]) {
			vis[w] = 1;
			if (m[w] < 0 || dfs(m[w], n, g, vis, m)) {
				m[w] = v;
				return 1;
			}
		}
	return 0;
}

int main()
{
	int n, i, j, m[256], ans;
	char g[256][256], vis[256];

	while (scanf("%d\n", &n) != EOF) {
		memset(g, 0, sizeof(g)), memset(m, -1, sizeof(m));
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				scanf("%c", &g[i][j]);
			getchar();
		}
		for (ans = i = 0; i < n; i++) {
			memset(vis, 0, sizeof(vis));
			if (!dfs(i, n, g, vis, m)) {
				printf("NO\n"), ans = 1;
				break;
			}
		}
		if (!ans)
			printf("YES\n");
	}
	return 0;
}
