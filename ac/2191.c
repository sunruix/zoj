#include <stdio.h>

int main()
{
	int a, b, c, f0, f1, f2, f3, f4, f5;
	while (scanf("%d %d %d", &f0, &f1, &f2) != EOF) {
		c = f0;
		a = (f2 - 2 * f1 + c) / 2;
		b = f1 - a - c;
		f3 = 9 * a + 3 * b + c;
		f4 = 16 * a + 4 * b + c;
		f5 = 25 * a + 5 * b + c;
		printf("%d %d %d\n", f3, f4, f5);
	}
	return 0;
}
