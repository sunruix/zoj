#include <stdio.h>

int main()
{
	int n, m, pre, cur, ans;
	while (scanf("%d", &n) != EOF && n) {
		ans = pre = 0, m = n;
		while (n--) {
			scanf("%d", &cur);
			if (cur > pre)
				ans += 6 * (cur - pre);
			else
				ans += 4 * (pre - cur);
			pre = cur;
		}
		printf("%d\n", ans + 5 * m);
	}
	return 0;
}
