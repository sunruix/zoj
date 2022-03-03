#include <stdio.h>
#include <string.h>

void init(int pos, int state, int m, long long ans[][1 << 11])
{
	if (pos == m)
		ans[0][state] = 1;
	else {
		if (pos < m)
			init(pos + 1, state << 1, m, ans);
		if (pos < m - 1)
			init(pos + 2, state << 2 | 3, m, ans);
	}
}

void dfs(int i, int pos, int cur, int pre, int m, long long ans[][1 << 11])
{
	if (pos == m)
		ans[i][cur] += ans[i - 1][pre];
	else {
		if (pos < m) {
			dfs(i, pos + 1, cur << 1, pre << 1 | 1, m, ans);
			dfs(i, pos + 1, cur << 1 | 1, pre << 1, m, ans);
		}
		if (pos < m - 1)
			dfs(i, pos + 2, cur << 2 | 3, pre << 2 | 3, m, ans);
	}
}

int main()
{
	int n, m, i;
	long long ans[16][1 << 11];

	while (scanf("%d %d", &n, &m) != EOF && n) {
		if (n * m & 1)
			printf("0\n");
		else {
			memset(ans, 0, sizeof(ans));
			if (n < m)
				n ^= m, m ^= n, n ^= m;
			init(0, 0, m, ans);
			for (i = 1; i < n; i++)
				dfs(i, 0, 0, 0, m, ans);
			printf("%lld\n", ans[n - 1][(1 << m) - 1]);
		}
	}
	return 0;
}