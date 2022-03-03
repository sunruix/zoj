#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int k, n, i, j;
	double m[128][16];

	while (scanf("%d %d", &k, &n) != EOF) {
		memset(m, 0, sizeof(m));
		for (i = 1; i <= k + 1; i++)
			m[n][i] = 1.0;
		for (i = n - 1; i >= 1; i--)
			for (j = 1; j <= k + 1; j++)
				m[i][j] = m[i + 1][j - 1] + m[i + 1][j] + m[i + 1][j + 1];
		for (i = 2; i <= k + 1; i++)
			m[1][1] += m[1][i];
		printf("%.5f\n", 100.0 * m[1][1] / pow(k + 1, n));
	}
	return 0;
}