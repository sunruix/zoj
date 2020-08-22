#include <stdio.h>
#include <string.h>

int prime[10000] = {2};

int isprime(int n)
{
	int i;
	for (i = 0; prime[i] * prime[i] <= n; i++)
		if (!(n % prime[i]))
			return 0;
	return n != 1;
}

int main()
{
	int n, i, j, k, dp[10001], index[10001], get[10001];

	for (i = 3, k = 1; i < 10001; i += 2)
		if (isprime(i))
			prime[k++] = i;
	memset(dp, 0, sizeof(dp)), dp[0] = 1;
	memset(index, 0, sizeof(index));
	for (i = 0; i < k; i++)
		for (j = prime[i]; j < 10001; j++) {
			if (dp[j - prime[i]]) {
				dp[j] = 1;
				if (!index[j] || index[j] > index[j - prime[i]] + 1)
					index[j] = index[j - prime[i]] + 1, get[j] = prime[i];
			}
		}
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", index[n]);
		for (i = n, j = index[i]; j >= 1; i -= get[i], j = index[i])
			printf("%d%c", get[i], j == 1 ? '\n' : ' ');
	}
	return 0;
}