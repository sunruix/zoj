#include <stdio.h>
#define inf 0x7ffffff

int main()
{
	int n, i, j, k, l, g[128][128], a[128], local, ansd, ansp, discon;
	freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) != EOF && n) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++)
				g[i][j] = inf;
			scanf("%d", &k);
			while (k--)
				scanf("%d %d", &j, &l), g[i][j] = l;
		}
		for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					g[i][j] > g[i][k] + g[k][j] ? g[i][j] = g[i][k] + g[k][j] : 0;
		for (i = 1; i <= n; g[i][i] = inf, i++);
		for (ansd = inf, i = 1; i <= n; i++) {
			for (local = 0, j = 1; j <= n; j++) {
				if (g[i][j] >= inf && i != j)
					break;
				g[i][j] > local && g[i][j] < inf ? local = g[i][j] : 0;
			}
			if (j > n)
				ansd > local && local > 0 ? ansd = local, ansp = i : 0;
		}
		if (ansp < 0 || ansd == inf)
			printf("disjoint\n");
		else
			printf("%d %d\n", ansp, ansd);
	}
	return 0;
}