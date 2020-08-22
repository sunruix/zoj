#include <stdio.h>

int main()
{
	int n, i, j, k, ans;
	int a[8] = {0, 9, 2 * 90, 3 * 900, 4 * 9000, 5 * 90000, 6 * 900000};
	int b[8] = {0, 1, 10, 100, 1000, 10000, 100000};
	char s[8];

	for (i = 2; i < 7; i++)
		a[i] += a[i - 1];
	while (scanf("%d", &n) != EOF) {
		for (i = 2; b[i] <= n; i++);
		i--;
		k = a[i - 1] + i * (n - b[i] + 1);
		for (i = 0, j = 0, ans = 1; k > 1; i = !i, j++) {
			k = i ? (k >> 1) : (k & 1 ? ((k >> 1) + 1) : (k >> 1));
			if (i)
				ans += (1 << j);
		}
		for (i = 1; a[i] < ans && i < 7; i++);
		j = (ans - a[i - 1]) / i;
		k = (ans - a[i - 1]) % i;
		ans = b[i] + j - 1 + (k ? 1 : 0);
		sprintf(s, "%d", ans);
		printf("%c\n", s[k ? k - 1 : i - 1]);
	}
	return 0;
}
