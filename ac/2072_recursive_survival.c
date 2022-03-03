#include <stdio.h>

long long J2(long long n)
{
	long long left = 1, d = 2, change = 0, m;

	while (1) {
		m = n;
		if (n & 1)
			n = change ? (n >> 1) : (n >> 1) + 1;
		else
			n >>= 1;
		if (n <= 1)
			break;
		change = change ^ (m & 1);
		if (change)
			left += d;
		d <<= 1;
	}
	return left;
}

int main()
{
	long long n, m, i, nn;

	while (scanf("%lld %lld", &n, &m) != EOF) {
		for (i = 1; i <= m; i++, n = nn) {
			nn = J2(n);
			if (nn == n)
				break;
		}
		printf("%lld\n", n);
	}
	return 0;
}