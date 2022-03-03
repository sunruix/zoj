#include <stdio.h>
#include <math.h>

int isprime(int n)
{
	int m, i;
	for (i = 2, m = sqrt(n); i <= m; i++)
	   if (n % i == 0)
		   return 0;
	return 1;
}

int main()
{
	int n, c, i, j, k, prime[1024];

	for (i = 1, j = 1; i <= 1000; i++)
		if (isprime(i))
			prime[j++] = i;
	prime[j] = 0x7fffffff;
	while (scanf("%d %d", &n, &c) != EOF) {
		for (i = 1, j = 0; prime[i] <= n; i++, j++);
		if (2 * c >= j)
			i = 1, k = j;
		else if (j % 2) {
			i = (j - 2 * c + 1) / 2 + 1;
			k = i + 2 * c - 2;
		}
		else {
			i = (j - 2 * c) / 2 + 1;
			k = i + 2 * c - 1;
		}
		printf("%d %d: ", n, c);
		for (; i < k; i++)
			printf("%d ", prime[i]);
		printf("%d\n\n", prime[i]);
	}
	return 0;
}
