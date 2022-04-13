#include <stdio.h>

int main()
{
	long long n, m, i, j, a, b, ans;

	while (scanf("%lld", &n) != EOF) {
		for (ans = 0, m = n, i = 1; m; i *= 10) {
			j = m % 10, m /= 10;
			ans += j > 1 ? ((m + 1) * i) : m * i + (j ? n % i + 1 : 0);
		}
		printf("%lld\n", ans);
	}
	return 0;
}