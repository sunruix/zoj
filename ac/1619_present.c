#include <stdio.h>

int main()
{
	int n, m, i;
	double ans, pre, ppre;

	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 2, ans = pre = 1.0, ppre = 0; i <= n - m - 1; i++)
			ans = (pre + ppre) * i, ppre = pre, pre = ans;
		for (i = 2; i <= n - m; i++)
			ans /= i;
		for (i = 2; i <= m; i++)
			ans /= i;
		if (m == n - 1)
			ans = 0;
		printf("%.8f\n", ans);
	}
	return 0;
}