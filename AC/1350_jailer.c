#include <stdio.h>

int main()
{
	int t, n, i, j, k, temp, ans;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans = 0;
		for (i = 2; i <= n; i++) {
			k = i / 2;
			temp = 0;
			for (j = 1; j <= k; j++)
				temp += !(i % j);
			ans += (temp + 1)% 2;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}
