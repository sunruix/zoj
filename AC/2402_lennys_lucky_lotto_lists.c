#include <stdio.h>
#include <string.h>

int main()
{
	int c, t, n, m, i, j, k;
	long long dp[16][2002];

	scanf("%d", &c);
	for (t = 1; t <= c; t++) {
		scanf("%d %d", &n, &m);
		for (i = 1 << (n - 1); i <= m; i++)
			dp[n][i] = 1;
		for (k = n - 1; k > 0; k--)
			for (i = 1 << (k - 1); i << (n - k) <= m; i++)
				for (dp[k][i] = 0, j = i << 1; j << (n - k - 1) <= m; j++)
					dp[k][i] += dp[k + 1][j];
		for (dp[0][0] = 0, i = 1; i << (n - 1) <= m; i++)
			dp[0][0] += dp[1][i];
		printf("Case %d: n = %d, m = %d, # lists = %lld\n", t, n, m, dp[0][0]);
	}
	return 0;
}
