#include <stdio.h>
#include <string.h>

int t, p, n, g[512][512], vis[512], i, j, k, ans;

int dfs(int v, int l)
{
	int w, x;

	if (v != i && !g[v][0])
		return g[v][0] = 1;
	vis[v] = 1;
	for (w = (l ? p + 1 : 1), x = (l ? p + n : p) ; w <= x; w++) {
		if (g[v][w] && !vis[w]) {
			if (dfs(w, !l)) {
				g[v][w] = 0, g[w][v] = 1;
				vis[v] = 0; return 1;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &t);
	while (t--) {
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));
		scanf("%d %d", &p, &n);
		for (i = 1; i <= p; i++) {
			scanf("%d", &k);
			while (k--)
				scanf("%d", &j), g[i][p + j] = 1;
		}
		for (i = ans = 1; i <= p && ans; i++)
			g[i][0] = ans = dfs(i, 1);
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
