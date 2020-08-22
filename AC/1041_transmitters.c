#include <stdio.h>
#include <math.h>

double dist(int x1, int y1, int x2, int y2) 
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
	int cx, cy, a[256][2], i, j, n, x, y, ans, up, below, va, vb;
	double r, k, b;

	while (scanf("%d %d %lf", &cx, &cy, &r) != EOF && r >= 0.0) {
		scanf("%d", &n);
		for (i = 0; n; n--) {
			scanf("%d %d", &x, &y); 
			if (dist(x, y, cx, cy) - r < 1e-6)
				a[i][0] = x, a[i++][1] = y;
		}
		n = i, ans = 0;
		for (i = 0; i < n; i++) {
			va = cy - a[i][1], vb = a[i][0] - cx;
			for (up = below = j = 0; j < n; j++)
				va * (a[j][0] - cx) + vb * (a[j][1] - cy) >= 0 ? up++ : below++;
			ans = up > ans ? up : ans;
			ans = below > ans ? below : ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}