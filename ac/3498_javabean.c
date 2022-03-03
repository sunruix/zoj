#include <stdio.h>

int main()
{
	int T, n, i, ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans = 0;
		while (n) {
			ans++;
			n /= 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
