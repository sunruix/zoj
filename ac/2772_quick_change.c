#include <stdio.h>

int main()
{
	int t, c, q, d, n, i;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d", &c);
		q = c / 25, c %= 25;
		d = c / 10, c %= 10;
		n = c / 5, c %= 5;
		printf("%d %d QUARTERS(S), ", i, q);
		printf("%d DIME(S), ", d);
		printf("%d NICKEL(S), ", n);
		printf("%d PENNY(S)\n", c);
	}
	return 0;
}