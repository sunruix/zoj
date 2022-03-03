#include <stdio.h>

int main()
{
	int i, j, k, a[8], end, ans;

	while (1) {
		for (end = i = 1; i < 7; i++) {
			scanf("%d", &a[i]);
			a[i] ? end = 0 : 0;
		}
		if (end)
			break;
		ans = a[6] + a[5] + a[4];
		a[1] -= 11 * a[5], a[2] -= 5 * a[4];
		a[2] < 0 ? a[1] += 4 * a[2] : 0;
		ans += a[3] / 4;
		if (j = a[3] % 4) {
			ans++;
			if (a[2] > 0) {
				j == 1 ? a[2] -= 5, k = 11: 0;
				j == 2 ? a[2] -= 3, k = 6: 0;
				j == 3 ? a[2] -= 1, k = 5: 0;
			}
			a[1] -= k;
		}
		if (a[2] > 0) {
			ans += a[2] / 9;
			(j = a[2] % 9) ? ans++, a[1] -= 36 - 4 * j : 0;
		}
		if (a[1] > 0) {
			ans += a[1] / 36;
			a[1] % 36 ? ans++ : 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}