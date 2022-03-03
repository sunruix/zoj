#include <stdio.h>

int main()
{
	long long m, n, i, ans, temp;

	while (scanf("%lld %lld", &m, &n) != EOF && (m || n)) {
		if (m > n)
			temp = m, m = n, n = temp;
		for (i = ans = 1; i <= m; i++)
			ans = ans * (n + i) / i;
		printf("%lld\n", ans);
	}
	return 0;
}