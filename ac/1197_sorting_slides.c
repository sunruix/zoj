#include <stdio.h>
#include <string.h>

int dfs(int v, int n, int g[][64], int *vis, int *m)
{
	int w;

	for (w = n; w < 2 * n; w++)
		if (g[v][w] && !vis[w]) {
			vis[w] = 1;
			if (m[w] < 0 || dfs(m[w], n, g, vis, m)) {
				m[w] = v, m[v] = w;
				return 1;
			}
		}
	return 0;
}

int hungary(int n, int g[][64], int *vis, int *m)
{
	int i, ans;

	memset(m, -1, 64 * sizeof(int));
	for (ans = i = 0; i < n; i++) {
		memset(vis, 0, 64 * sizeof(int));
		if (dfs(i, n, g, vis, m))
			ans++;
	}
	return ans;
}

int main()
{
	int n, i, j, k, l, g[64][64], h[64][4], vis[64], m[64], m1[64], m2[64], max, ans, count = 1;

	while (scanf("%d", &n) != EOF && n) {
		memset(g, 0, sizeof(g));
		for (i = 0; i < n; i++)
			scanf("%d %d %d %d", &h[i][0], &h[i][1], &h[i][2], &h[i][3]);
		for (i = n; i < 2 * n; i++) {
			scanf("%d %d", &k, &l);
			for (j = 0; j < n; j++)
				if (k > h[j][0] && k < h[j][1] && l > h[j][2] && l < h[j][3])
					g[i][j] = g[j][i] = 1;
		}
		max = hungary(n, g, vis, m);
		memset(m2, -1, sizeof(m2));
		for (ans = i = 0; i < n; i++) {
			if (m[i] > 0) {
				g[i][m[i]] = 0;
				if (max != hungary(n, g, vis, m1))
					ans++, m2[i] = m[i];
				g[i][m[i]] = 1;
			}
		}
		printf("Heap %d\n", count++);
		if (ans) {
			for (i = 0; ans; i++)
				if (m2[i] > 0)
					printf("(%c,%d)%c", 'A' + i, m2[i] - n + 1, ans != 1 ? ' ' : '\n'), ans--;
			printf("\n");
		}
		else
			printf("none\n\n");
	}
	return 0;
}