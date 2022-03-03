#include <stdio.h>

int main()
{
	int t, x1, y1, x2, y2, r1, r2;
	double x, y;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &x1, &y1, &r1);
		scanf("%d %d %d", &x2, &y2, &r2);
		if (r1 == r2 || (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 - r2) * (r1 - r2)) {
			printf("Impossible.\n");
			continue;
		}	
		x = (double)(r1 * x2 - r2 * x1) / (r1 - r2);
		y = (double)(r1 * y2 - r2 * y1) / (r1 - r2);
		printf("%.2f %.2f\n", x, y);
	}
	return 0;
}