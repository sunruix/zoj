#include <stdio.h>

int main()
{
	int i, j, k, l, m, n, a[16], b[16], map[16];
	long long ans;

	while (scanf("%d", &m) != EOF) {
		for (i = 0, n = 0; i < m; i++) {
			scanf("%d", &a[i]);
			map[a[i]] = 0;
			n += a[i];
		}
		ans = 1;
		for (i = 0; i < m; i++) {
			++map[a[i]];
			for (j = 2; j <= a[i]; j++)
				b[j] = j;
			for (j = n; j > n - a[i]; j--) {
				for (k = 2, l = j; k <= a[i]; k++)
					if (l % b[k] == 0)
						l /= b[k], b[k] = 1;
				ans *= l;
			}
			for (k = 2; k <= a[i]; k++)
				ans /= b[k];
			n -= a[i];
			ans /= map[a[i]];
		}
		printf("%Ld\n", ans);
	}
	return 0;
}
