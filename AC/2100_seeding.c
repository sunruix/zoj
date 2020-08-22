#include <stdio.h>
#include <string.h>

int dfs(int i, int j, char g[][8], char vis[][8], int n, int m)
{
	int ii, jj, k, res, max = 0, dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

	for (vis[i][j] = 1, k = 0; k < 4; k++) {
		ii = i + dir[k][0], jj = j + dir[k][1];
		if (ii >= 0 && ii < n && jj >= 0 && jj < m && g[ii][jj] == '.' && !vis[ii][jj]) {
			res = dfs(ii, jj, g, vis, n, m);
			if (max < res)
				max = res;
		}
	}
	vis[i][j] = 0;
	return max + 1;
}

int main()
{
	int n, m, i, j, k;
	char g[8][8], vis[8][8];

	while (scanf("%d %d\n", &n, &m) != EOF && n) {
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));
		for (k = i = 0; i < n; i++)
			for (j = 0; j <= m; j++)
				if ((g[i][j] = getchar()) == '.')
					k++;
		printf("%s\n", dfs(0, 0, g, vis, n, m) == k ? "YES" : "NO");
	}
	return 0;
}