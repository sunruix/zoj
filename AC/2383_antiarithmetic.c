#include <stdio.h>

int main()
{
	int n, i, j, k, l, a[10001], ans;

	while (scanf("%d:", &n) != EOF && n) {
		for (i = 0; i < n; i++)
			scanf("%d", &j), a[j] = i;
		for (ans = 1, l = (n >> 1) - !(n & 1), k = -1 * l; k < 0 && ans; k++)
			for (i = n - 1; i + 2 * k >= 0; i--)
				if (a[i] < a[i + k] && a[i + k] < a[i + 2 * k])
					ans = 0;
		for (k = 1; k <= l && ans; k++)
			for (i = 0; i + 2 * k < n; i++)
				if (a[i] < a[i + k] && a[i + k] < a[i + 2 * k])
					ans = 0;
		printf("%s\n", ans ? "yes" : "no");
	}
	return 0;
}