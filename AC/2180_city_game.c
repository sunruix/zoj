#include <stdio.h>

int main()
{
	int t, m, n, i, j, k, col_sum[1001], sum, ans;
	char g[1001][1001];

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d\n", &m, &n), ans = 0;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				scanf("%c ", &g[i][j]);
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++)
				col_sum[j] = g[i][j] == 'R' ? 0 : 1;
			for (j = i; j < m; j++) {
				for (sum = k = 0; k < n; k++) {
					if (!col_sum[k] || g[j][k] == 'R')
						col_sum[k] = 0, sum = 0;
					else {
						col_sum[k] = j == i ? 1 : col_sum[k] + 1;
						sum += col_sum[k];
						if (ans < sum)
							ans = sum;
					}
				}
			}
		}
		printf("%d\n", 3 * ans);
	}
	return 0;
}