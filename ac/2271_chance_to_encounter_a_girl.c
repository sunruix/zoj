#include <stdio.h>
#include <string.h>

int main()
{
	int n, m, d, i, j, k, l, ii, jj, dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
	double dp[2][100][100], ans, temp;

	while (scanf("%d", &n) != EOF) {
		memset(dp, 0, sizeof(dp));
		m = n >> 1;
		dp[0][m][m] = 1, ans = 0;
		for (d = 0; d < n; d++) {
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (dp[d & 1][i][j] != 0.0 && (i != m || j != d - 1)) {
						for (l = k = 0; k < 4; k++) {
							ii = i + dir[k][0], jj = j + dir[k][1];
							if (ii >= 0 && ii < n && jj >= 0 && jj < n)
								l++;
						}
						if (!l)
							continue;
						temp = 1.0 / l;
						for (k = 0; k < 4; k++) {
							ii = i + dir[k][0], jj = j + dir[k][1];
							if (ii >= 0 && ii < n && jj >= 0 && jj < n)
								dp[!(d & 1)][ii][jj] += dp[d & 1][i][j] * temp;
						}
					}
				}
			}
			ans += dp[!(d & 1)][m][d];
			memset(dp[d & 1], 0, sizeof(dp[0]));
		}
		printf("%.4f\n", ans);
	}
	return 0;
}