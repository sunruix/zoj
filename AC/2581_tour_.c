#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dist(int a[][], int i, int j)
{
	int x, y;
	x = a[i][0] - a[j][0];
	y = a[i][1] - a[j][1];
	return sqrt(x * x + y * y);
}

double slope(int a[][], int i, int j)

int main()
{
	int n, i, map[1024];
	double d;

	freopen("input1", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d %d", &map[i].x, &map[i].y);
		for (i = 0, d = 0; i < n - 1; i++)
			d += dist(map[i], map[i + 1]);
		d += dist(map[0], map[n - 1]);
		printf("%.2f\n", d);
	}
	return 0;
}
