#include <stdio.h>

int main()
{
	long long n, ans;
	while (scanf("%Ld", &n) != EOF && n) {
		ans = n * (n - 1) / 2;
		ans = ans % n ? (ans / n + 1) : (ans / n);
		printf("%Ld\n", ans);
	}
	return 0;
}
