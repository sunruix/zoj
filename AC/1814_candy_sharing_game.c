#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j, k[2], max, min, *a;

	while (scanf("%d", &n) != EOF && n) {
		a = (int *)malloc(n * sizeof(int));
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (j = 1; ; j++) {
			max = 0, min = 0x7fffffff;
			for (k[0] = a[n - 1] >> 1, i = 0; i < n; i++) {
				k[!(i & 1)] = a[i] >> 1;
				a[i] = (a[i] >> 1) + k[i & 1];
				a[i] & 1 ? a[i]++ : 0;
				max < a[i] ? max = a[i] : 0;
				min > a[i] ? min = a[i] : 0;
			}
			if (max == min)
				break;
		}
		printf("%d %d\n", j, max);
	}
	return 0;
}