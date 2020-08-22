#include <stdio.h>
#include <string.h>

int main()
{
	long long n, k, i, j, m[32][256];

	memset(m, 0, sizeof(m));
	for (n = 1; n <= 20; n++)
		for (m[n][0] = 1, m[n][j = n * (n - 1) >> 1] = 1, k = 1; k < j; k++)
			for (i = k; i >= k - n + 1; i--)
				m[n][k] += m[n - 1][i];
	while (scanf("%lld %lld", &n, &k) != EOF && n)
		printf("%lld\n", m[n][k]);
	return 0;
}