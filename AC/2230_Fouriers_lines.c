#include <stdio.h>

int main()
{
	int t = 1, n, m, i, j;
	char a[101][10001];

	memset(a, 0, sizeof(a));
	for (a[1][0] = 1, n = 2; n <= 100; n++)
		for (a[n][0] = a[n][n - 1] = a[n][n * (n - 1) >> 1] = 1, i = 2; i <= n - 2; i++)
			for (j = 0; j <= i * (i - 1) >> 1; j++)
				a[i][j] ? a[n][i * (n - i) + j] = 1 : 0;
	while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
		printf("Case %d: ", t++);
		if (a[n][m])
			printf("%d lines with exactly %d crossings can cut the plane into %d pieces at most.\n", n, m, n + m + 1);
		else
			printf("%d lines cannot make exactly %d crossings.\n", n, m);
	}
	return 0;
}