#include <stdio.h>

int main()
{
	int n, m, i, j, a[32768], ans;
	while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
		for (i = 0; i <= n; i++)
			a[i] = 0;
		for (i = 0, ans = 0; i < m; i++) {
			scanf("%d", &j);
			if (!a[j])
				a[j] = 1;
			else if (a[j] > 0) {
				a[j] = -1;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
