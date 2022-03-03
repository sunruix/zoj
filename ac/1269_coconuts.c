#include <stdio.h>

int main()
{
	int n, i, x, left, ans;

	while (scanf("%d", &n) != EOF && n >= 0) {
		for (ans = 0, x = n; x > 1; x--) {
			left = n;
			for (i = 0; i < x && !((left - 1) % x); i++)
				left -= left / x + 1;
			if (i == x && !(left % x)) {
				ans = x;
				break;
			}
		}
		printf("%d coconuts, ", n);
		ans ? printf("%d people and 1 monkey\n", ans) : printf("no solution\n");
	}
	return 0;
}
					