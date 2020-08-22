#include <stdio.h>

int a[512][512], ans[512][512];

int main()
{
	int n, i, j, k, l, count = 1;
	int b[3][3] = {1, 2, 1, 2, 4, 2, 1, 2, 1};

	while (scanf("%d", &n) != EOF && n) {
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &a[i][j]), ans[i][j] = a[i][j];
		for (i = 2; i <= n - 1; i++) {
			for (j = 2; j <= n - 1; j++) {
				ans[i][j] = 0;
				for (k = 1; k <= 3; k++)
					for (l = 1; l <= 3; l++)
						ans[i][j] += a[i + k - 2][j + l - 2] * b[k - 1][l - 1];
				ans[i][j] /= 16;
			}
		}
		printf("Case %d:\n", count++);
		for (i = 1; i <= n; i++) {
			for (j = 1; j < n; j++)
				printf("%d ", ans[i][j]);
			printf("%d\n", ans[i][j]);
		}
	}
	return 0;
}