#include <stdio.h>

int main()
{
	int t, n, m, i, j, k, ans;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		m = n, ans = 1;
		for (i = 2; i * i <= m; i++) {
			if (!(m % i)) {
				k = j = 1;
				while (!(m % i))
					j *= i, k += j, m /= i;
				ans *= k;
			}
		}
		if (m != 1)
			ans *= (m + 1);
		if (n == 1)
			printf("0\n");
		else
			printf("%d\n", ans - n);
	}
	return 0;
}
