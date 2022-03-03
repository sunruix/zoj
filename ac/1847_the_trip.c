#include <stdio.h>

int main()
{
	int n, i, a[1024], aver, r, s, ans;

	while (scanf("%d", &n) != EOF && n) {
		for (aver = i = 0; i < n; i++)
			scanf("%d.%d", &r, &s), a[i] = 100 * r + s, aver += a[i];
		for (r = aver % n, s = n - r, aver /= n, ans = i = 0; i < n; i++) {
			if (a[i] > aver)
				r ? (ans += a[i] - aver - 1, r--) : (ans += a[i] - aver);
			else
				s ? (ans += aver - a[i], s--) : (ans += aver + 1 - a[i]);
		}
		printf("$%.2lf\n", (double)ans / 200);
	}
	return 0;
}