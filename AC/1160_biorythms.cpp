#include <stdio.h>

int main()
{
	int t, p, e, i, d, n, count;

	scanf("%d\n", &t);
	while (t--) {
		count = 1;
		while (scanf("%d %d %d %d", &p, &e, &i, &d) != EOF
			&& p >= 0 && e >= 0 && i >= 0 && d >= 0) {
			p %= 23, e %= 28, i %= 33;
			p = 23 - p + d, e = 28 - e + d, i = 33 - i + d;
			for (n = 1; ((n + p) % 23 || (n + e) % 28 || (n + i) % 33); n++);
			printf("Case %d: the next triple peak occurs in %d days.\n", count++, n);
		}
		if (t)
			printf("\n");
	}
	return 0;
}