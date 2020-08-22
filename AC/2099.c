#include <stdio.h>

int main()
{
	int x, y, maxx, maxy, minx, miny;
	while (scanf("%d %d", &x, &y) != EOF && (x || y)) {
		maxx = minx = x, maxy = miny = y;
		while (scanf("%d %d", &x, &y) != EOF && (x || y)) {
			if (maxx < x)
				maxx = x;
			if (minx > x)
				minx = x;
			if (maxy < y)
				maxy = y;
			if (miny > y)
				miny = y;
		}
		printf("%d %d %d %d\n", minx, miny, maxx, maxy);
	}
	return 0;
}
