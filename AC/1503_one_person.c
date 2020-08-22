#include <stdio.h>

int main()
{
	int t = 1, g, l, i, j, m[32][32];

	for (i = 0; i < 32; m[0][i++] = 0);
	for (i = 0; i < 32; m[i++][0] = i);
	while (scanf("%d %d", &g, &l) != EOF && (g || l)) {
		for (i = 1; i <= g; i++)
			for (j = 1; j <= l; j++)
				m[i][j] = m[i - 1][j] + 1 + m[i - 1][j - 1];
		printf("Case %d: %d\n", t++, m[g][l]);
	}
	return 0;
}