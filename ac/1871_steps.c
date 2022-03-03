#include <stdio.h>
#include <math.h>
#define func(x) (int)((sqrt(1 + 8.0 * x) - 1) / 2)

int main()
{
	int a, b, n, m, i, k, ans;

	while (scanf("%d %d", &a, &b) != EOF) {
		n = (b - a) >> 1, m = b - a - n;
		n = func(n), m = func(m);
		k = b - a - (n * (n + 1) >> 1) - (m * (m + 1) >> 1);
		k / (n + 1) ? (ans = k / (n + 1), k %= n + 1) : (ans = 0);
		ans += n + m + (k ? k / n + !!(k % n) : 0);
		printf("%d\n", ans);
	}
	return 0;
}