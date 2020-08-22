#include <stdio.h>
#include <math.h>

long long gcd (long long n, long long m)
{
	int p;
	if (n < m)
		p = n, n = m, m = p;
	while (p = n % m)
		n = m, m = p;
	return m;
}

int main()
{
	long long n, nn, i, j, sqt, ans, m[128];
	while (scanf("%Ld", &n) != EOF && n) {
		nn = n > 0 ? n : -n;
		sqt = sqrt(nn);
		for (i = 2, j = 0; i <= sqt; i++) {
			if (!(nn % i)) {
				m[j] = 0;
				while (!(nn % i))
					m[j]++, nn /= i;
				j++;
			}
		}
		if (j == 0)
			ans = 1;
		else {
			for (i = 1, ans = m[0]; i < j; i++)
				ans = gcd(ans, m[i]);
			if (n < 0 && !(ans % 2))
				while (!(ans % 2))
					ans /= 2;
		}
		printf("%Ld\n", ans);
	}
	return 0;
}

