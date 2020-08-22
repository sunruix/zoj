#include <stdio.h>
#include <math.h>

int isprime(long long  n)
{
	long long m, i;
	for (i = 2, m = sqrt(n); i <= m; i++)
		if (!(n % i))
			return 0;
	return 1;
}

int main()
{
	long long n, m, i, j, prime[32768];
	int flag;

	while (scanf("%Ld", &n) != EOF && n > 0) {
		for (i = 2, flag = 1; i <= n; i++) {
			if (flag && isprime(n)) {
				printf("%Ld\n", n);
				break;
			}
			if (!(n % i) && isprime(i)) {
				printf("%Ld\n", i);
				n /= i, i = 1;
				flag = 1;
			}
			else
				flag = 0;
		}
		printf("\n");
	}
	return 0;
}
