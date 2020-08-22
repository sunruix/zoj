#include <stdio.h>
#include <string.h>

int dfs(int v, int ny, char g[][2048], char *vis, int *mat)
{
	int w;

	for (w = 0; w < ny; w++)
		if (g[v][w] && !vis[w]) {
			vis[w] = 1;
			if (mat[w] < 0 || dfs(mat[w], ny, g, vis, mat)) {
				mat[w] = v;
				return 1;
			}
		}
	return 0;
}

int main()
{
	int T, t, m, n, i, j, x[64][64], y[64][64], mat[2048], nx, ny, ans, k;
	char map[64][64], g[2048][2048], vis[2048];

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		memset(g, 0, sizeof(g)), memset(mat, -1, sizeof(mat));
		scanf("%d %d", &m, &n);
		for (i = 0; i < m; i++)
			scanf("%s", map[i]);
		for (nx = i = 0; i < m; i++)
			for (j = 0; j < n; ) {
				for (; j < n && map[i][j] == '#'; j++);
				if (j < n) {
					for (; j < n && map[i][j] != '#'; j++)
						x[i][j] = nx;
					nx++;
				}
			}
		for (ny = i = 0; i < n; i++)
			for (j = 0; j < m; ) {
				for (; j < m && map[j][i] == '#'; j++);
				if (j < m) {
					for (; j < m && map[j][i] != '#'; j++)
						y[j][i] = ny;
					ny++;
				}
			}
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				map[i][j] == 'o' ? g[x[i][j]][y[i][j]] = 1 : 0;
		for (ans = i = 0; i < nx; i++)
			memset(vis, 0, sizeof(vis)), ans += dfs(i, ny, g, vis, mat);
		printf("Case :%d\n%d\n", t, ans);
	}
	return 0;
}
