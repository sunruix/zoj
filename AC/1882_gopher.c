#include <stdio.h>
#include <string.h>

int dfs(int v, int m, char g[][128], char *vis, char *mat)
{
	int i;

	for (i = 1; i <= g[v][0]; i++)
		if (!vis[g[v][i]]) {
			vis[g[v][i]] = 1;
			if (mat[g[v][i]] < 0 || dfs(mat[g[v][i]], m, g, vis, mat)) {
				mat[g[v][i]] = v;
				return 1;
			}
		}
	return 0;
}

int main()
{
	int n, m, s, v, i, j, k, ans;
	char g[128][128], vis[128], mat[128];
	double gp[128][2], x, y;

	while (scanf("%d %d %d %d", &n, &m, &s, &v) != EOF) {
		memset(g, 0, sizeof(g)), memset(mat, -1, sizeof(mat));
		for (i = 0; i < n; i++)
			scanf("%lf %lf", &gp[i][0], &gp[i][1]);
		for (i = 0; i < m; i++) {
			scanf("%lf %lf", &x, &y);
			for (j = 0; j < n; j++)
				if ((x - gp[j][0]) * (x - gp[j][0]) + (y - gp[j][1]) * (y - gp[j][1]) -
					s * s * v * v < 1e-4)
					g[i][++g[i][0]] = j;
		}
		for (ans = n, i = 0; i < n; i++)
			memset(vis, 0, sizeof(vis)), ans -= dfs(i, m, g, vis, mat);
		printf("%d\n", ans);
	}
	return 0;
}