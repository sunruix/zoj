#include <stdio.h>
#include <string.h>

void dfs(int v, int root, int g[][32], int gg[][32], int *vis)
{
	int w;

	vis[v] = 1;
	for (w = 0; w < 26; w++)
		if (g[v][w] && !vis[w]) {
			if (!g[root][w])
				gg[root][w] = 1;
			dfs(w, root, g, gg, vis);
		}
}

int main()
{
	int t, n, i, j, k, g[32][32], gg[32][32], vis[32], ans;
	char c1, c2, c3;

	scanf("%d", &t);
	for (k = 1; k <= t; k++) {
		memset(g, 0, sizeof(g));
		scanf("%d\n", &n);
		while (n--) {
			scanf("%c%c%c\n", &c1, &c3, &c2);
			c3 == '<' ? (g[c1 - 'A'][c2 - 'A'] = 1) : (g[c2 - 'A'][c1 - 'A'] = 1);
		}
		printf("Case %d:\n", k);
		for (ans = i = 0; i < 26; i++) {
			memset(vis, 0, sizeof(vis));
			memset(gg, 0, sizeof(gg));
			dfs(i, i, g, gg, vis);
			for (j = 0; j < 26; j++)
				gg[i][j] ? printf("%c<%c\n", i + 'A', j + 'A'), ans = 1: 0;
		}
		if (!ans)
			printf("NONE\n");
	}
	return 0;
}