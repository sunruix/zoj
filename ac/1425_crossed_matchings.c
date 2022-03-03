#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
	int t, n, m, i, j, ii, jj, a[128], b[128], dp[128][128];

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (j = 1; j <= m; j++)
			scanf("%d", &b[j]);
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (a[i] != b[j]) {
					for (jj = j - 1; jj > 0 && b[jj] != a[i]; jj--);
					for (ii = i - 1; ii > 0 && a[ii] != b[j]; ii--);
					if (ii && jj)
						dp[i][j] = max(dp[i][j], dp[ii - 1][jj - 1] + 2);
				}
			}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}