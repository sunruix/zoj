#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
	int n, i, j, k, dp[2][32768], score[128], ls, lt;
	char s[32768], t[32768], c;

	while (scanf("%d\n", &n) != EOF) {
		while (n--)
			scanf("%c %d\n", &c, &k), score[c] = k;
		scanf("%s %s", s + 1, t + 1), ls = strlen(s + 1), lt = strlen(t + 1);
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= ls; i++)
			for (j = 1; j <= lt; j++) {
				if (s[i] == t[j])
					dp[i & 1][j] = score[s[i]] + dp[!(i & 1)][j - 1];
				else
					dp[i & 1][j] = max(dp[i & 1][j - 1], dp[!(i & 1)][j]);
			}
		printf("%d\n", dp[ls & 1][lt]);
	}
	return 0;
}