#include <stdio.h>
#include <math.h>

int main()
{
	int n, m, i, j, k, l, ans, sq, N, M, prime;

	while (scanf("%d %d", &n, &m) != EOF) {
		N = n, M = m;
		if (!m || (n <= 1 && m > 1))
			ans = 0;
		else if (n >= m || m == 1)
			ans = 1;
		else {
			prime = ans = 1;
			for (i = 2; i * i <= m; i++) {
				if (!(m % i)) {
					prime = k = 0;
					while (!(m % i))
						m /= i, k++;
					for (j = i; j <= n; j++) {
						l = j;
						if (!(l % i)) {
							while (!(l % i))
								l /= i, k--;
							if (k <= 0)
								break;
						}
					}
					if (k > 0) {
						ans = 0;
						break;
					}
				}
			}
			if (prime && M > N)
				ans = 0;
		}
		printf("%d %s %d!\n", M, ans ? "divides" : "does not divide", N);
	}
	return 0;
}
