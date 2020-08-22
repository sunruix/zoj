#include <stdio.h>
#include <math.h>

int main()
{
	int n, d, l, ansn, ansd;
	double a, min, diff, div;

	while (scanf("%lf", &a) != EOF) {
		scanf("%d", &l), ansn = l, ansd = 1;
		for (min = 100000, d = 1; d <= l; d++)
			for (n = (int)(a * d) ? (int)(a * d) : 1; n <= l; n++) {
				div = (double)n / (double)d;
				if (div - a > min)
					break;
				diff = fabs(div - a);
				if (min > diff)
					min = diff, ansn = n, ansd = d;
			}
		printf("%d %d\n", ansn, ansd);
	}
	return 0;
}