#include <stdio.h>

int main()
{
	int t, n, i, j, k, l, a[10], ans;

	for (i = j = 1, a[i] = 0; i <= 9; i++)
		a[i] = 9 * j, j *= 10;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 1, k = l = 0; i <= 9 && n > 0; i++)
			for (j = 1; j <= a[i] && n > 0; j++, l++)
				k += i, n -= k;
		if (!n)
			ans = l % 10;
		else {
			for (i = 1, l = 0, n += k; i <= 9 && n > 0; i++)
				for (j = 1; j <= a[i] && n > 0; j++, l++)
					n -= i;
			for (; n < 0; n++)
				l /= 10;
			ans = l % 10;
		}
		printf("%d\n", ans);
	}
	return 0;

}