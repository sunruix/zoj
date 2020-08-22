#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, n = 1;
	while (scanf("%d %d %d", &a, &b, &c) != EOF && (a || b || c)) {
		printf("Triangle #%d\n", n++);
		if (c == -1) {
			if (a <= 0 || b <= 0)
				printf("Impossible.\n");
			else
				printf("c = %.3f\n", sqrt(a * a + b * b));
		}
		else if (b == -1) {
			if ((a <= 0 || c <= 0) || a >= c)
				printf("Impossible.\n");
			else
				printf("b = %.3f\n", sqrt(c * c - a * a));
		}
		else {
			if ((b <= 0 || c <= 0) || b >= c)
				printf("Impossible.\n");
			else
				printf("a = %.3f\n", sqrt(c * c - b * b));
		}
		printf("\n");
	}
	return 0;
}
