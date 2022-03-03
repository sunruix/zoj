#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

/*int t, n, m, i, j, k, a[50005], b[50005], dp[50005 + 50005 / 3][4];*/
int main()
{
	int t, n, m, i, j, k, a[50005], b[50005], dp[50005 + 50005 / 3][4];
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for (b[0] = 0, i = 0; i < m; i++)
			b[0] += a[i];
		for (j = 1; i < n; i++, j++)
			b[j] = b[j - 1] + a[i] - a[j - 1];
		for (i = n - m; i >= 0; i--)
			for (j = 1; j <= 3; j++)
				dp[i][j] = max(dp[i + 1][j], dp[i + m][j - 1] + b[i]);
		printf("%d\n", dp[0][3]);
	}
	return 0;
}