#include <stdio.h>

int main()
{
	int T, d, t;
	double ans1, ans2;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &d, &t);
		ans1 = (2.5 / 4.0) * t;
		ans2 = (2.0 / 5.0) * t;
		if (d > 10) {
			ans1 += 3.75 * (d - 10) + 2.5 * 7;
			ans2 += 3.00 * (d - 10) + 2.0 * 7;
		}
		else if (d > 3) {
			ans1 += 2.5 * (d - 3);
			ans2 += 2.0 * (d - 3);
		}
		printf("%d\n", (int)(0.5 + ans1) - (int) (0.5 + ans2));
	}
	return 0;
}