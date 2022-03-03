#include <stdio.h>
#include <string.h>
#include <math.h>

int issquare(int n)
{
	int m = (int)sqrt(n);

	return m * m == n;
}

int main()
{
	int t, n, i, j, a[64][2048], p[64];

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(p, 0, sizeof(p));
		for (i = 1;; i++) {
			for (j = 0; j < n; j++)
				if (!p[j] || issquare(a[j][p[j]] + i)) {
					a[j][++p[j]] = i;
					break;
				}
			if (j == n)
				break;
		}
		printf("%d\n", i - 1);
	}
	return 0;
}