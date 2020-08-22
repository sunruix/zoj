#include <stdio.h>
#include <string.h>

int n, g[512][512], vis[512], boys[512], girls[512], bc, gc, i, j, k, l, ans;

int dfs(int v)
{
	int w;

	vis[v] = 1;
	for (w = 0; w < n; w++)
		if (g[v][w] && !vis[w]) {
			if (!g[w][n] || dfs(w)) {
				g[v][w] = 0, g[w][v] = 1, g[w][n] = -1;
				vis[v] = 0; return 1;
			}
		}
	vis[v] = 0; return 0;
}

void part(int v, int sex)
{
	int w;

	vis[v] = 1;
	if (sex)
		g[v][n] = 1, boys[bc++] = v;
	else
		girls[gc++] = v;
	for (w = 0; w < n; w++)
		if (g[v][w] && !vis[w])
			part(w, !sex);
}

int main()
{
	freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < n; i++) {
			scanf("%d: (%d)", &j, &k);
			while (k--)
				scanf("%d", &l), g[l][j] = g[j][l] = 1;
		}
		for (i = bc = gc = 0; i < n; i++)
			if (!vis[i])
				part(i, 1);
		memset(vis, 0, sizeof(vis)), ans = 0;
		for (i = 0; i < gc; i++)
			memset(g[girls[i]], 0, sizeof(g[girls[i]]));
		for (i = 0; i < bc; i++)
			for (j = 0; j < n; j++)
				if (g[boys[i]][j] && !g[j][n]) {
					g[boys[i]][j] = 0, g[j][boys[i]] = 1, g[j][n] = g[boys[i]][n] = -1;
					ans++;
					break;
				}
		for (i = 0; i < bc; i++) {
			memset(vis, 0, sizeof(vis));
			if (g[boys[i]][n] > 0 && dfs(boys[i]))
				ans++;
		}
		printf("%d\n", n - ans);
	}
	return 0;
}