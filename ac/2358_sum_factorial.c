#include <stdio.h>
#include <string.h>

#define limit 0x7fffffff

int work (int n, int fac[], int i)
{
	int max1 = 0, max2 = 0;
	if (i < 0 || n < 0)
		return 0;
	max1 = work(n, fac, i - 1);
	if (n >= fac[i])
		max2 = work(n - fac[i], fac, i - 1) + fac[i];
	return max1 > max2 ? max1 : max2;
}

int main()
{
	int n, sum[64], fac[64], i, last;

	fac[0] = 1;
	for (i = 1; i < 64; i++) {
		if ((limit / i) <= fac[i - 1])
			break;
		fac[i] = fac[i - 1] * i;
	}
	last = i - 1;
	while (scanf("%d", &n) != EOF && n >= 0) {
		if (n != work(n, fac, last) || n == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
