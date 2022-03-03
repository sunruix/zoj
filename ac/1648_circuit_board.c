#include <stdio.h>

typedef struct {
	double x, y;
} point;

typedef struct {
	point p1, p2;
} segment;

double direction(point p1, point p2, point p3)
{
	return (p1.x - p2.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p1.y - p2.y);
}

int intersect(segment s1, segment s2)
{
	double d1, d2, d3, d4;

	d1 = direction(s1.p1, s1.p2, s2.p1);
	d2 = direction(s1.p1, s1.p2, s2.p2);
	d3 = direction(s2.p1, s2.p2, s1.p1);
	d4 = direction(s2.p1, s2.p2, s1.p2);
	return (d1 * d2 < 0 && d3 * d4 < 0);
}

int main()
{
	int n, i, j, ans;
	segment s[2048];

	while (scanf("%d", &n) != EOF) {
		for (ans = 1, i = 0; i < n; i++) {
			scanf("%lf %lf %lf %lf", &s[i].p1.x, &s[i].p1.y, &s[i].p2.x, &s[i].p2.y);
			for (j = 0; j < i && ans; j++)
				ans = !intersect(s[i], s[j]);
		}
		printf("%s\n", ans ? "ok!" : "burned!");
	}
	return 0;
}
