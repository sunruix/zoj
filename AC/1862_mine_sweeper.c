#include <stdio.h>

int main()
{
	int n, i, j, k, ii, jj, d[8][2] = {0, -1, -1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1}, count = 0;
	char g[16][16], h[16][16], c, bomb;

	while (scanf("%d\n", &n) != EOF) {
		if (count++)
			printf("\n");
		for (i = 0; i < n; i++) {
			for (j = 0; j <= n; j++)
				g[i][j] = getchar();
		}
		for (bomb = i = 0; i < n; i++) {
			for (j = 0; j <= n; j++) {
				h[i][j] = getchar();
				if (h[i][j] == 'x') {
					if (g[i][j] == '*') {
						bomb = 1;
						continue;
					}
					for (h[i][j] = '0', k = 0; k < 8; k++) {
						ii = i + d[k][0], jj = j + d[k][1];
						if (ii >= 0 && ii < n && jj >= 0 && jj < n && g[ii][jj] == '*')
							h[i][j]++;
					}
				}
			}
		}
		if (bomb)
			for (i = 0; i < n; i++)
				for (j = 0; j <= n; j++)
					printf("%c", g[i][j] == '*' ? g[i][j] : h[i][j]);
		else
			for (i = 0; i < n; i++)
				for (j = 0; j <= n; j++)
					printf("%c", h[i][j]);
	}
	return 0;
}