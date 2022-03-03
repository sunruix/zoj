#include <stdio.h>
#include <string.h>
#define reg(a, b) (((a) == '(' && (b) == ')') || ((a) == '[' && (b) == ']'))

int main()
{
	int t, i, j, k, l, n, reg, dp[128][128];
	char s[128], ss[128], m[128][128][128];

	scanf("%d\n", &t);
	while (t--) {
		fgets(s, sizeof(s), stdin), n = strlen(s) - 1;
		fgets(ss, sizeof(ss), stdin);
		if (n) {
			memset(dp, 0, sizeof(dp)), memset(m, 0, sizeof(m));
			for (l = 1; l < n; l++)
				for (i = 0, j = i + l; i + l < n; i++, j = i + l) {
					if (reg(s[i], s[j])) {
						dp[i][j] = 2 + dp[i + 1][j - 1];
						m[i][j][i] = m[i][j][j] = 1;
						if (l > 1)
							memcpy(m[i][j] + i + 1, m[i + 1][j - 1] + i + 1, j - i - 1);
					}
					for (k = i; k < j; k++)
						if (dp[i][j] < dp[i][k] + dp[k + 1][j]) {
							dp[i][j] = dp[i][k] + dp[k + 1][j];
							memcpy(m[i][j] + i, m[i][k] + i, k - i + 1);
							memcpy(m[i][j] + k + 1, m[k + 1][j] + k + 1, j - k);
						}
				}
			for (i = 0; i < n; i++)
				if (m[0][n - 1][i])
					printf("%c", s[i]);
				else
					printf("%s", s[i] == '(' || s[i] == ')' ? "()" : "[]");
		}
		printf("\n%s", t ? "\n" : "");
	}
	return 0;
}