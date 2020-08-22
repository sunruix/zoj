#include <stdio.h>
#include <math.h>
#define eps 1e-8
#define f(x, a) (log((x)) / (x) - (log((a)) / (a)))

int main()
{
	double a, x, y, l, r, m, e = exp(1);
	freopen("input.txt", "r", stdin);
	while (scanf("%lf", &a) != EOF) {
		if (a / log(a) - e < eps)
			printf("-1\n");
		else if (a - e > eps)
			printf("-1\n");
		else {
			l = e, r = l + 1;
			while (f(r, a) > eps)
				l = r, r = l + 1;
			while (1) {
				m = (l + r) / 2;
				if (fabs(y = f(m, a)) < eps)
					break;
				else if (y > eps)
					l = m + 0.00001;
				else
					r = m - 0.00001;
			}
			printf("%.5lf\n", m);
		}
	}
	return 0;
}
