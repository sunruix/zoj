#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	double diameter, x1, y1, x2, y2, x3, y3, d1, d2, d3, p;
	const double pi = 3.141592653589793;

	while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
		d1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		d2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
		d3 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
		p = (d1 + d2 + d3) / 2;
		diameter = d1 * d2 * d3 / 2 / sqrt(p * (p - d1) * (p - d2) * (p - d3));
		printf("%.2f\n", pi * diameter);
	}
	return 0;
}
