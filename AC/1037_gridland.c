#include <stdio.h>
#include <math.h>

int main()
{
	int n, a, b, i;
	float c, d;

	c = sqrt(2);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		if ((a % 2) && (b % 2))
			d = c + a * b - 1;
		else
			d = a * b;
		printf("Scenario #%d:\n", i);
		printf("%.2f\n\n", d);
	}
	return 0;
}
