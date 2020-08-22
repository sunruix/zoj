#include <stdio.h>
#include <string.h>

double v[100001], dp[2][100001];

int main()
{
	int n, m, i, j, k, a[128], b[100001], err;

	while (scanf("%d %d", &m, &n) != EOF && m) {
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= m; i++)
			scanf("%d", &a[i]);
		for (i = 1; i <= n; i++)
			scanf("%d %lf", &b[i], &v[i]);
		for (err = 0, i = k = 1; i <= m && !err; i++) {
			for (; k <= n && a[i] != b[k]; k++);
			k > n ? err = 1 : 0;
			for (j = k, dp[i & 1][j - 1] = 1e10; j <= n; j++)
				if (a[i] != b[j])
					dp[i & 1][j] = dp[i & 1][j - 1];
				else
					dp[i & 1][j] = v[j] + dp[!(i & 1)][j - 1] < dp[i & 1][j - 1] ?
						v[j] + dp[!(i & 1)][j - 1] : dp[i & 1][j - 1];
		}
		if (err)
			printf("Impossible\n");
		else
			printf("%.2f\n", dp[m & 1][n]);
	}
	return 0;
}