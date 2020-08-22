#include <stdio.h>

int main()
{
	int n, i, fac[16];

	fac[0] = 1;
	for (i = 1; i < 11; i++)
		fac[i] = i * fac[i - 1];

	while (scanf("%d", &n) != EOF && n >= 0) {
		if (!n) {
			printf("NO\n");
			continue;
		}
		for (i = 10; i >= 0 && n; i--)
			if (fac[i] <= n)
				n -= fac[i];
		if (!n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
