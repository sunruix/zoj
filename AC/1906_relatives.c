#include <stdio.h>
#include <math.h>

int n, prime[1024];

int fac(int n, int prime[])
{
	int i, j, k;
	for (i = 2, j = 0, k = sqrt(n); i <= k; i++) {
		if (!(n % i))
			prime[j++] = i;
		while (!(n % i))
			n /= i;
	}
	if (n != 1)
		prime[j++] = n;
	return j;
}

int dfs(int s, int l, int x, int m)
{
	int i, res;
	if (!l)
		return ((n - 1) / x);
	for (i = s + 1, res = 0; i + l - 1 < m; i++)
		res += dfs(i, l - 1, x * prime[i], m);
	return res;
}

int main()
{
	int i, j, m, ans;
	while (scanf("%d", &n) != EOF && n) {
		m = fac(n, prime);
		for (i = 0, ans = 0; i < m; i++) {
			for (j = 0; j + i < m; j++) {
				if (i % 2)
					ans -= dfs(j, i, prime[j], m);
				else
					ans += dfs(j, i, prime[j], m);
			}
		}
		printf("%d\n", n - 1 - ans);
	}
	return 0;
}
