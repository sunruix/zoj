#include <stdio.h>

int main()
{
	long long x, y, i, ans, m, p, q, r;

	while (scanf("%lld %lld", &x, &y) != EOF) {
		m = x * y;
		for (ans = 0, i = x; i <= y; i += x) {
			if (m % i == 0) {
				if (m / i > i)
					p = m / i, q = i;
				else
					p = i, q = m / i;
				while (r = p % q)
					p = q, q = r;
				if (q == x)
					ans++;
			}
		}
		printf("%Ld\n", ans);
	}
	return 0;
}