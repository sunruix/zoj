#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

char dp[10000001];

int main()
{
	int n, m, i, j, a, sum;

	while (scanf("%d %d", &n, &m) != EOF) {
		memset(dp, 0, sizeof(dp));
		for (dp[0] = 1, sum = i = 0; i < n; i++) {
			scanf("%d", &a);
			for (sum += a, j = sum < m ? sum : m; !dp[m] && j >= a; j--)
				dp[j] = dp[j] || dp[j - a];
		}
		for (i = m; m >= 0 && !dp[i]; i--);
		printf("%d\n", i);
	}
	return 0;
}