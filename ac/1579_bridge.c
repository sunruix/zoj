#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	long long va = *(long long *)a, vb = *(long long *)b;
	if (va != vb)
		return va > vb ? 1 : -1;
	return 0;
}

int main()
{
	long long n, i, a[100001], ans;

	while (scanf("%lld", &n) != EOF) {
		for (ans = 0, i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		qsort(a + 1, n, sizeof(long long), comp);
		while (n > 3) {
			ans += (a[2] << 1) > a[1] + a[n - 1] ? (a[1] << 1) + a[n - 1] + a[n] : a[1] + (a[2] << 1) + a[n];
			n -= 2;
		}
		if (n == 1)
			ans += a[1];
		else if (n == 2)
			ans += a[2];
		else if (n == 3)
			ans += a[1] + a[2] + a[3];
		printf("%lld\n", ans);
	}
	return 0;
}
		
