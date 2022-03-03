#include <stdio.h>

int t, n, l, a, b, c, d, maxa, maxb;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &l, &n);
		maxa = maxb = 0;
		while (n--) {
			scanf("%d", &a);
			b = l - a, c = a, d = b;
			a = a < b ? a : (b = c, d);
			maxa = a > maxa ? a : maxa;
			maxb = b > maxb ? b : maxb;
		}
		printf("%d %d\n", maxa, maxb);
	}
	return 0;
}
			