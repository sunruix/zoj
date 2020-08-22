#include <stdio.h>
#include <math.h>

int main()
{
	long long t, n, sq, i, j, k, ans;

	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		for (ans = 0, sq = sqrt(n), i = 1; i <= sq; i++) {
			j = n / i, ans += j;
			i != j ? (k = n / (i + 1), ans += (j - k) * (i - 1)) : 0;
		}
		printf("%lld\n", ans - sq);
	}
	return 0;
}
