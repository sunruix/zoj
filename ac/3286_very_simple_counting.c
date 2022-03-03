#include <stdio.h>

int fac[1000001], count[1000000], prime[1000000], ans[1000001], i, ii, j, k, n, m;

int main()
{
	for (fac[1] = 1, fac[2] = 2, prime[0] = 2, j = 1, n = 3; n <= 1000000; n++) {
		for (ii = 0; n % prime[ii] && prime[ii] * prime[ii] <= n; ii++);
		for (i = n, k = 0; !(i % prime[ii]); k++, i /= prime[ii]);
		if (k)
			fac[n] = (k + 1) * fac[i], ans[n] = count[fac[n]]++;
		else
			fac[n] = 2, ans[n] = j, prime[j++] = n;
	}
	while (scanf("%d", &n) != EOF)
		printf("%d\n", ans[n]);
	return 0;
}
