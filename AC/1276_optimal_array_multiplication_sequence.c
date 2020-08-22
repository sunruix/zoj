#include <stdio.h>
#include <string.h>

int path[16][16];

void print(int i, int j)
{
	if (j - i < 2)
		printf("A%d", j);
	else if (j - i == 2)
		printf("(A%d x A%d)", j - 1, j);
	else {
		printf("("), print(i, path[i][j]);
		printf(" x ");
		print(path[i][j], j), printf(")");
	}
}

int main()
{
	int n, i, j, k, a[16], m[16][16], temp, count = 0;

	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; i++)
			scanf("%d %d", &a[i], &a[i + 1]);
		memset(m, 0, sizeof(m));
		for (j = 2; j < n + 1; j++)
			for (i = 0; i + j < n + 1; i++)
				for (k = i + 1; k < i + j; k++) {
					temp = a[i] * a[k] * a[i + j] + m[i][k] + m[k][i + j];
					if (!m[i][i + j] || m[i][i + j] > temp)
						m[i][i + j] = temp, path[i][i + j] = k;
				}
		printf("Case %d: ", ++count);
		print(0, n);
		printf("\n");

	}
	return 0;
}