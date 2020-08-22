#include <stdio.h>

const int max = 1000000;
int ans[3392929], prime[78499];

int isprime(int n)
{
	int i;

	if ((n != 2 && !(n % 2)) || (n != 3 && !(n % 3)) || (n != 5 && !(n % 5)) && (n != 7 && !(n % 7)))
		return 0;
	for (i = 0; prime[i] * prime[i] <= n; i++)
		if (!(n % prime[i]))
			return 0;
	return n != 1;
}

int main()
{
	int n, m, i, j, k, sum;

	for (prime[0] = 2, j = 1, i = 3; i < max; i += 2)
		if (isprime(i))
			prime[j++] = i;
	for (n = 1; n <= max; n++) {
		for (m = n, sum = 1, i = 0; prime[i] * prime[i] <= m; i++) {
			if (!(m % prime[i])) {
				j = k = 1;
				while (!(m % prime[i]))
					j *= prime[i], k += j, m /= prime[i];
				sum *= k;
			}
		}
		if (m != 1)
			sum *= (m + 1);
		ans[sum - n]++;
	}
	for (ans[0] = 1, i = 1; i < 3392929; i++)
		ans[i] += ans[i - 1];
	while (scanf("%d", &m) != EOF)
		printf("%d\n", m > 3392928 ? 1000000 : ans[m]);
	return 0;
}
