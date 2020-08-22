#include <stdio.h>
#include <math.h>

int main()
{
	int D, V;
	double d;
	const double pi = 3.1415927;

	while (scanf("%d %d", &D, &V) != EOF && (D || V)) {
		d = (double)D * D * D - (6 * V / pi);
		d = pow(d, 1.0 / 3);
		printf("%.3f\n", d);
	}
	return 0;
}