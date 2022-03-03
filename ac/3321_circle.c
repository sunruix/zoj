#include <stdio.h>

int n, m, g[16][16], vi[16];

void dfs(int v)
{
	int w;
	vi[v] = 1;
	for (w = 1; w <= n; w++)
		if (g[v][w] && ! vi[w])
			break;
	if (w <= n)
		dfs(w);
}

int main()
{
	int i, v, w, d[16], ans;

	while (scanf("%d %d", &n, &m) != EOF) {
		ans = 1;
		for (v = 1; v <= n; v++) {
			d[v] = vi[v] = 0;
			for (w = 1; w <= n; w++)
				g[v][w] = g[w][v] = 0;
		}
		for (i = 0; i < m; i++) {
			scanf("%d %d", &v, &w);
			g[v][w] = g[w][v] = 1;
			d[v]++, d[w]++;
		}
		if (m != n)
			ans = 0;
		for (v = 1; v <= n && ans; v++)
			if (d[v] != 2)
				ans = 0;
		if (ans) {
			dfs(1);
			for (v = 1; v <= n && ans; v++)
				if (!vi[v])
					ans = 0;
		}
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
