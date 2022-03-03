#include <stdio.h>

int main()
{
	double a, b, r1, r2, l, w, R, r;

	while (scanf("%lf %lf %lf %lf", &a, &b, &r1, &r2) != EOF) {
		l = a > b ? a : b;
		w = a < b ? a : b;
		R = r1 > r2 ? r1 : r2;
		r = r1 < r2 ? r1 : r2;
		if (w - 2.0 * R < 0.01)
			printf("No\n");
		else if (2.0 * (R + r) < l + 0.01)
			printf("Yes\n");
		else if ((l - R - r) * (l - R - r) + (w - R - r) * (w - R - r)
			< (R + r) * (R + r) + 0.01)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}