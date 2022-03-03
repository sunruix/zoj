#include <stdio.h>

int main()
{
	int T, m, n, i, j, a[128], b[128], c, d, min, ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &m, &n);
		for (i = 0; i < m; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &b[i]);
		for (j = 0; j < n; j++) {
			min = 128;
			for (i = 0; i < m; i++) {
				c = a[i] ^ b[j];
				d = 0;
				while (c) {
					d += c % 2;
					c /= 2;
				}
				if (min > d || (min == d && ans > a[i])) {
					min = d;
					ans = a[i];
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
