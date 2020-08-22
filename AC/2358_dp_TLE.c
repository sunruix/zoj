#include <stdio.h>
#include <string.h>

int main()
{
	int n, fac[16], i, j, f[1024 * 1024];
	int max1, max2;
	fac[0] = 1;
	for (i = 1; i < 10; i++) {
		fac[i] = i * fac[i - 1];
	}
	while (scanf("%d", &n) != EOF && n >= 0) {
		if (n == 0) {
			printf("NO\n");
			continue;
		}
		memset(f, 0, sizeof(f));
		for (i = 0; i < 10; i++) {
			for (j = n; j >= 0; j--) {
				max1 = f[j];
				if (j - fac[i] >= 0)
					max2 = f[j - fac[i]] + fac[i];
				else
					max2 = 0;
				f[j] = max1 > max2 ? max1 : max2;
			}
		}
		if (f[n] == n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
