#include <stdio.h>
#include <string.h>

int n, m, t;
char g[8][8], vis[8][8];

int dfs(int ii, int jj, int len)
{
	int i, j, k, dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

	for (vis[ii][jj] = 1, k = 0; len <= t && k < 4; k++) {
		i = ii + dir[k][0], j = jj + dir[k][1];
		if (i >= 0 && i < n && j >= 0 && j < m && g[i][j] != 'X' && !vis[i][j]) {
			if (g[i][j] == 'D' && len == t)
				return 1;
			else if (g[i][j] == '.' && dfs(i, j, len + 1))
				return 1;
		}
	}
	vis[ii][jj] = 0;
	return 0;
}

int main()
{
	int i, j, k, ii, jj;

	while (scanf("%d %d %d\n", &n, &m, &t) != EOF && n) {
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < n; i++)
			for (j = 0; j <= m; j++)
				if ((g[i][j] = getchar()) == 'S')
					ii = i, jj = j;
		printf("%s\n", dfs(ii, jj, 1) ? "YES" : "NO");
	}
	return 0;
}
