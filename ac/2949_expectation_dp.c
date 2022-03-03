#include <stdio.h>
#include <math.h>

int main()
{
	int t, n, i, j, k, up, down;
	double exp, comb, power;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		power = pow(0.5, n - 1);
		comb = power;
		exp = n * comb;
		for (k = n + 1; k < 2 * n; k++) {
			comb *= (double)(k - 1) / (double)(k - n)/ 2;
			exp += k * comb;
		}
		printf("%.2f\n", exp);
	}
	return 0;
}
