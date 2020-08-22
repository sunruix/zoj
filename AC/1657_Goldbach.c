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
	int i, j, n, a, b, prime[16384], count;

	prime[0] = 2;
	for (i = 3, j = 1; i < 32768 && j < 16384; i += 2)
		if (isprime(i))
			prime[j++] = i;
	while (scanf("%d", &n) != EOF && n) {
		count = 0;
		for (i = 0; i < j; i++) {
			a = prime[i], b = n - a;
			if (a > b) {
				printf("%d\n", count);
				break;
			}
			if (isprime(b))
				count++;
		}
	}
	return 0;
}
