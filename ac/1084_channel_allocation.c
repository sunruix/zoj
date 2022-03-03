#include <stdio.h>
#include <string.h>

int dfs(int v, int n, char g[32][32], char *vis, char *p)
{
	int w, i;

	vis[v] = 1, p[++p[0]] = v;
	for (w = 0; w < n; w++)
		if (g[v][w] && !vis[w]) {
			for (i = 1; i <= p[0] && g[w][p[i]]; i++);
			if (i > p[0])
				dfs(w, n, g, vis, p);
		}
	return 0;
}

int main()
{
	int n, i, j, ans;
	char v, w, g[32][32], vis[32], p[32];

	while (scanf("%d\n", &n) != EOF && n) {
		memset(g, 1, sizeof(g)), memset(p, 32, sizeof(p)), memset(vis, 0, sizeof(vis));
		for (i = 0; i < n; i++) {
			scanf("%c:", &v), g[v - 'A'][v - 'A'] = 0;
			while ((w = getchar()) != EOF && w != '\n')
				g[v - 'A'][w - 'A'] = 0;
		}
		for (ans = i = 0; i < n; i++)
			if (!vis[i]) {
				memset(p, 0, sizeof(p));
				dfs(i, n, g, vis, p), ans++;
			}
		if (ans == 1)
			printf("1 channel needed.\n");
		else
			printf("%d channels needed.\n", ans);
	}
	return 0;
}
		