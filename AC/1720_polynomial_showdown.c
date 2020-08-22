#include <stdio.h>

void print_item(int coe, int exp)
{
	if (exp) {
		coe == 1 ? printf("x") : printf("%dx", coe);
		exp == 1 ? 0 : printf("^%d", exp);
	}
	else
		printf("%d", coe);
}

int main()
{
	int a[16], i;

	while (scanf("%d", &a[0]) != EOF) {
		for (i = 1; i < 9; i++)
			scanf("%d", &a[i]);
		for (i = 0; a[i] == 0 && i < 8; i++);
		if (i < 8) {
			a[i] > 0 ? print_item(a[i], 8 - i) : (putchar('-'), print_item(-1 * a[i], 8 - i));
			for (i++; i < 9; i++)
				if (a[i])
					a[i] > 0 ? (printf(" + "), print_item(a[i], 8 - i)) : (printf(" - "), print_item(-1 * a[i], 8 - i));
		}
		else
			printf("%d", a[i]);
		putchar('\n');
	}
	return 0;
}