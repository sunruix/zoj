#include <stdio.h>
#include <math.h>

int main()
{
	double lo, n, ans;

	while (scanf("%lf", &n) != EOF) {
		lo = n * log10(n);
		lo = lo - (long long)(lo);
		ans = pow(10, lo);
		printf("%d\n", (int)ans);
	}
	return 0;
}