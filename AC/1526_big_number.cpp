#include <stdio.h>
#include <math.h>

int main()
{
	int t, n, i;
	double ans;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 1 || n == 2 || n == 3)
			printf("1\n");
		else {
			for (ans = log10(6.0), i = 4; i <= n; i++)
				ans += log10((double)i);
			printf("%d\n", (int)ans + 1);
		}
	}
	return 0;
}