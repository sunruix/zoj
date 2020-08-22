#include <stdio.h>

int main()
{
	int n, m, a[10001], c, i, j, ans, record[5001];
	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 0; i < m; i++)
			record[i] = 0;
		for (a[0] = 0, i = 1; i <= n; i++) {
			scanf("%d", &c);
			a[i] = a[i - 1] + c;
			record[a[i] % m]++;
		}
		for (i = 0, ans = 0; i < m; i++)
			ans += (record[i] * (record[i] - 1)) / 2;
		ans += record[0];
		printf("%d\n", ans);
	}
	return 0;
}
