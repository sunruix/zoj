#include <stdio.h>

int main()
{
	int n, i, v, t, ans, len = 45 * 360;

	while (scanf("%d", &n) != EOF && n) {
		for (ans = 0x7fffffff, i = 0; i < n; i++) {
			scanf("%d %d", &v, &t);
			t >= 0 && ans > t + len / v + !!(len % v) ? ans = t + len / v + !!(len % v) : 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}