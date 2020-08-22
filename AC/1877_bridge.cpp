#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, i, a[1024], ans, m1, m2;

	while (scanf("%d", &n) != EOF) {
		for (m = n, ans = 0, i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		while (m > 3) {
			m1 = (a[1] << 1) + a[m] + a[m - 1], m2 = a[1] + (a[2] << 1) + a[m];
			ans += m1 < m2 ? m1 : m2, m -= 2;
		}
		if (n == 1)
			ans += a[1];
		else if (m == 2)
			ans += a[2];
		else
			ans += a[1] + a[2] + a[3];
		printf("%d\n", ans);
		while (n > 3) {
			if ((a[1] << 1) + a[n] + a[n - 1] < a[1] + (a[2] << 1) + a[n])
				printf("%d %d\n%d\n%d %d\n%d\n", a[1], a[n - 1], a[1], a[1], a[n], a[1]);
			else
				printf("%d %d\n%d\n%d %d\n%d\n", a[1], a[2], a[1], a[n - 1], a[n], a[2]);
			n -= 2;
		}
		if (n == 1)
			printf("%d\n", a[1]);
		else if (n == 2)
			printf("%d %d\n", a[1], a[2]);
		else if (n == 3)
			printf("%d %d\n%d\n%d %d\n", a[1], a[3], a[1], a[1], a[2]);
	}
	return 0;
}
