#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, j, k, p, q, r, a[64], ans;

	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = ans = 0; i < n; i++)
			for (j = i + 1; j < n; j++) {
				p = a[i] > a[j] ? a[i] : a[j];
				q = a[i] < a[j] ? a[i] : a[j];
				while (r = p % q)
					p = q, q = r;
				if (q == 1)
					ans++;
			}
		if (ans)
			printf("%f\n", sqrt((double)n * (n - 1) * 6 / (2 * ans)));
		else
			printf("No estimate for this data set.\n");
	}
	return 0;
}