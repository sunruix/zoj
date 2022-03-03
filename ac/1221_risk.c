#include <stdio.h>

int main()
{
	int t = 1, i, j, k, g[32][32], n;

	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= 20; i++)
			for (j = 1; j <= 20; j++)
				g[i][j] = 1024;
		while (n--)
			scanf("%d", &j), g[1][j] = g[j][1] = 1;
		for (i = 2; i < 20; i++) {
			scanf("%d", &n);
			while (n--)
				scanf("%d", &j), g[i][j] = g[j][i] = 1;
		}
		for (k = 1; k <= 20; k++)
			for (i = 1; i <= 20; i++)
				for (j = 1; j <= 20; j++)
					if (g[i][j] > g[i][k] + g[k][j])
						g[i][j] = g[i][k] + g[k][j];
		scanf("%d", &n), printf("Test Set #%d\n", t++);
		while (n--)
			scanf("%d %d", &i, &j), printf("%d to %d: %d\n", i, j, g[i][j]);
		printf("\n");
	}
	return 0;
}