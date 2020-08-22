#include <stdio.h>

long long check(long long a, long long b, long long d)
{
	long long i, aa, dd;

	for (i = 0, aa = a % b, dd = d % b; i < b; i++)
		if ((aa * i % b) == dd)
			break;
	if (i == b)
		return -1;
	return (a * i - d) / b + i;
}

int main()
{
	long long t, A, B, a, b, dist, ans, i, j;
	freopen("input.txt", "r", stdin);
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld %lld %lld", &A, &B, &a, &b);
		dist = A > B ? A - B : B - A;
		ans = dist / (a + b);
		dist %= (a + b);
		i = check(a, b, dist), j = check(b, a, dist);
		if (i < 0 && j < 0)
			ans = -1;
		else if (i > 0 && (i < j || j < 0))
			ans += i;
		else
			ans += j;
		printf("%lld\n", ans);
	}
	return 0;
}