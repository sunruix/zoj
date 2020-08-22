#include <stdio.h>

const int max = 2000000000;

int main()
{
	int n, i, j, k, l, a[128];
	char ans[256];

	for (a[1] = 9, i = 2; a[i - 1] <= max && a[i - 1] > 0; i++)
		a[i] = i & 1 ? a[i - 1] * 10 : a[i - 1];
	while (scanf("%d", &n) != EOF && n) {
		for (i = 1; n > 0; i++)
			n -= a[i];
		n += a[--i];
		l = i & 1 ? (i >> 1) + 1 : i >> 1;
		if (l > 1) {
			ans[l] = '0' + (n - 1) % 10, n = n % 10 ? n / 10 : n / 10 - 1;
			for (j = l - 1; j > 1; j--)
				ans[j] = '0' + n % 10, n /= 10;
			ans[j] = '0' + (n + 1) % 10;
		}
		else
			ans[l] = '0' + n % 10;
		ans[l + 1] = '\0', printf("%s", ans + 1);
		for (j = i & 1 ? l - 1 : l; j >= 1; j--)
			printf("%c", ans[j]);
		printf("\n");
	}
	return 0;
}
