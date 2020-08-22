#include <stdio.h>

int main()
{
	int t, n, a, odd, even, ans;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n), ans = n & 1, odd = even = 0;
		while (n--)
			scanf("%d", &a), odd += a * (n & 1), even += a * (!(n & 1));
		ans = ans ? 1 : (odd - even < 2 && odd - even > -2 ? 1 : 0);
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}