#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, r1, c1, r2, c2, ans;
	char g[16][16];

	while (scanf("%s", &g[0]) != EOF) {
		for (ans = 0, i = 1; i < 8; i++)
			scanf("%s", &g[i]);
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		r1--, c1--, r2--, c2--;
		if ((fabs(r1 - r2) == 1 && c1 == c2) || (fabs(c1 - c2) == 1 && r1 == r2)) {
			g[r1][c1] ^= g[r2][c2], g[r2][c2] ^= g[r1][c1], g[r1][c1] ^= g[r2][c2];
			for (i = 0; i < 8 && !ans; i++)
				for (j = 1; j < 7 && !ans; j++)
					ans = g[i][j] == g[i][j - 1] && g[i][j] == g[i][j + 1];
			for (j = 0; j < 8 && !ans; j++)
				for (i = 1; i < 7 && !ans; i++)
					ans = g[i][j] == g[i - 1][j] && g[i][j] == g[i + 1][j];
		}
		printf("%s\n", ans ? "Ok!" : "Illegal move!");
	}
	return 0;
}