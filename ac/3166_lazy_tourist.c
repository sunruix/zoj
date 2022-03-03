#include <stdio.h>
#include <string.h>

void Floyd_Warshall(int n, int g[][128])
{
	int i, j, k;

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (g[i][k] > 0 && g[k][j] > 0)
					if (g[i][j] < 0 || g[i][j] > g[i][k] + g[k][j])
						g[i][j] = g[i][k] + g[k][j];
}

int main()
{
	int n, m, hotel[128], g[128][128], i, j, k, ans, min;

	while (scanf("%d %d", &n, &m) != EOF) {
		memset(hotel, 0, sizeof(hotel)), memset(g, -1, sizeof(g));
		while (m--)
			scanf("%d", &i), hotel[i] = 1;
		scanf("%d", &m);
		while (m--)
			scanf("%d %d %d", &i, &j, &k), g[i][j] = k;
		Floyd_Warshall(n, g);
		for (min = 0x7fffffff, ans = i = 1; i <= n; i++)
			if (hotel[i] && g[i][i] > 0 && g[i][i] < min)
				min = g[i][i], ans = i;
		min == 0x7fffffff ? printf("I will nerver go to that city!\n") : printf("%d\n", ans);
	}
	return 0;
}