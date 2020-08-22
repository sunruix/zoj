#include <stdio.h>
#include <math.h>

int isprime(int n)
{
	int i, m;
	m = sqrt(n);
	for (i = 2; i <= m; i++)
		if (!(n % i))
			return 0;
	return 1;
}

int main()
{
	int i, j, n, a, b, prime[512 * 1024];

	prime[0] = 2;
	for (i = 3, j = 1; i < 1000 * 1000 && j < 500 * 1000; i += 2)
		if (isprime(i))
			prime[j++] = i;
	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < j; i++) {
			a = prime[i], b = n - a;
			if (isprime(b)) {
				printf("%d = %d + %d\n", n, a, b);
				break;
			}
		}
	}
	return 0;
}
