#include <stdio.h>
#include <string.h>

int n, m, dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int dfs(int v, int g[][128], int *vis, int *match)
{
	int k, i, j, ii, jj, w;

	v % m ? (i = v / m + 1, j = v % m) : (i = v / m, j = m);
	for (k = 0; k < 4; k++) {
		ii = i + dir[k][0], jj = j + dir[k][1];
		if (ii > 0 && ii <= n && jj > 0 && jj <= m && !g[ii][jj]) {
			w = (ii - 1) * m + jj;
			if (!vis[w]) {
				vis[w] = 1;
				if (!match[w] || dfs(match[w], g, vis, match)) {
					match[w] = v;
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, k, g[128][128], match[128 * 128], vis[128 * 128], ans;

	while (scanf("%d %d", &n, &m) != EOF && n) {
		memset(g, 0, sizeof(g)), memset(match, 0, sizeof(match));
		scanf("%d", &k);
		while (k--)
			scanf("%d %d", &i, &j), g[i][j] = 1;
		for (ans = 0, i = 1; i <= n; i++)
			for (j = i & 1 ? 1 : 2; j <= m; j += 2) {
				memset(vis, 0, sizeof(vis));
				!g[i][j] ? ans += dfs((i - 1) * m + j, g, vis, match) : 0;
			}
		printf("%d\n", ans);
	}
	return 0;
}
