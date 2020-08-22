#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct {
	double x, y;
} node;

double dist(node a, node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int check(double a, double b)
{
	if (fabs(a - b) < 1e-6)
		return 1;
	return 0;
}

int main()
{
	int t, i, j, k, ans, count = 0;
	double d[8];
	node a[4];
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		for (i = k = ans = 0; i < 4; i++) {
			scanf("%lf %lf", &a[i].x, &a[i].y);
			for (j = 0; j < i; j++)
				d[k++] = dist(a[i], a[j]);
		}
		sort(d, d + 6);
		if (!check(d[0], 0.0) && check(d[0], d[1]) && check(d[0], d[2]) &&
			check(d[0], d[3]) && check(d[4], d[5]) && check(d[0] * sqrt(2.0), d[5]))
			ans = 1;
		if (count++)
			printf("\n");
		printf("Case %d:\n", count);
		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

			