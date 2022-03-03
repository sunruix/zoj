#include <stdio.h>
#include <string.h>

int n, g[512][512], vis[512], boys[512], girls[512], bc, gc, i, j, k, l, ans;

int dfs(int v)
{
	int w;

	for (w = 0; w < n; w++)
		if (g[v][w] && !vis[w]) {
			vis[w] = 1;
			if (g[w][n] < 0 || dfs(g[w][n])) {
				g[w][n] = v;
				return 1;
			}
		}
	return 0;
}

void part(int v, int sex)
{
	int w;

	vis[v] = 1;
	if (sex)
		boys[bc++] = v;
	else
		girls[gc++] = v;
	for (w = 0; w < n; w++)
		if (g[v][w] && !vis[w])
			part(w, !sex);
}

int main()
{
	while (scanf("%d", &n) != EOF) {
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < n; i++) {
			scanf("%d: (%d)", &j, &k);
			while (k--)
				scanf("%d", &l), g[j][l] = 1;
			g[i][n] = -1;
		}
		for (i = bc = gc = 0; i < n; i++)
			if (!vis[i])
				part(i, 1);
		for (i = 0, ans = 0; i < bc; i++) {
			memset(vis, 0, sizeof(vis));
			if (dfs(boys[i]))
				ans++;
		}
		printf("%d\n", n - ans);
	}
	return 0;
}