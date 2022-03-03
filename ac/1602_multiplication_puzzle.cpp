#include <stdio.h>

int main()
{
	int n, i, j, k, min, a[128], m[128][128];

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]), m[i][i] = m[i][i + 1] = 0;
		for (j = 2; j < n; j++)
			for (i = 0; i + j < n; i++)
				for (k = i + 1, m[i][i + j] = 0x7fffffff; k < i + j; k++) {
					min = a[i] * a[k] * a[i + j] + m[i][k] + m[k][i + j];
					if (min < m[i][i + j])
						m[i][i + j] = min;
				}
		printf("%d\n", m[0][n - 1]);
	}
	return 0;
}