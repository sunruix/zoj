#include <stdio.h>
#include <string.h>

int dfs(int v, int n, char g[][128], char *vis, char *mat)
{
	int i;

	for (i = 1; i <= g[v][0]; i++)
		if (!vis[g[v][i]]) {
			vis[g[v][i]] = 1;
			if (!mat[g[v][i]] || dfs(mat[g[v][i]], n, g, vis, mat)) {
				mat[g[v][i]] = v; return 1;
			}
		}
	return 0;
}

int main()
{
	int t, n, m, i, j, k, ans;
	char g[128][128], vis[128], mat[128];

	scanf("%d", &t);
	while (t--) {
		memset(g, 0, sizeof(g)), memset(mat, 0, sizeof(mat)), memset(vis, 0, sizeof(vis));
		scanf("%d %d", &n, &m);
		while (m--)
			scanf("%d %d", &i, &j), g[i][++g[i][0]] = j;
		for (ans = n, i = 1; i <= n; i++)
			memset(vis, 0, sizeof(vis)), ans -= dfs(i, n, g, vis, mat);
		printf("%d\n", ans);
	}
	return 0;
}
