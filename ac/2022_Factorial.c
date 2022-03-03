#include <stdio.h>

int main()
{
	int t, n, i, ans;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 5, ans = 0; i <= n; i *= 5)
			ans += n / i;
		printf("%d\n", ans);
	}
	return 0;
}
