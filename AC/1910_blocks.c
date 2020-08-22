#include <stdio.h>

int main()
{
	int t, n, i, j, k, m, min, fac[1024];

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 2, j = 1; i <= n; i++)
			if (!(n % i))
					fac[j++] = i;
		m = j, fac[0] = 1;
		for (i = 0, min = 0x7fffffff; i < m; i++)
			for (j = i; j < m; j++)
				for (k = j; k < m; k++)
					if (fac[i] * fac[j] * fac[k] == n &&
						(min > (fac[i] * fac[j] + fac[j] * fac[k] + fac[k] * fac[i]) << 1)) {
						min = (fac[i] * fac[j] + fac[j] * fac[k] + fac[k] * fac[i]) << 1;
						break;
					}
		printf("%d\n", min);
	}
	return 0;
}