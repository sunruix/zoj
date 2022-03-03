#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	if (*(double *)a - *(double *)b > 0)
		return 1;
	else
		return -1;
}

int main()
{
	int T, n, i;
	double a[512];
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		qsort(a, n, sizeof(double), comp);
		if (n % 2)
			printf("%.3f\n", a[n / 2]);
		else
			printf("%.3f\n", (a[n / 2 - 1] + a[n / 2]) / 2);
	}
	return 0;
}
