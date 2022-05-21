#include <stdio.h>
#include <string.h>

int main()
{
	int k, i, j, nozero = 0;
	double a[2048], b[2048], c[2048];
	double result2[128];
	int result1[128];

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	memset(result2, 0, sizeof(result2));
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d", &j);
		scanf("%lf", &a[j]);
	}
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d", &j);
		scanf("%lf", &b[j]);
	}
	for (i = 0; i < 2048; i++) {
		if (a[i] == 0)
			continue;
		for (j = 0; j < 2048; j++) {
			if (b[j] == 0)
				continue;
			c[i + j] += a[i] * b[j];
		}
	}
	for (i = 2047, j = 0; i >= 0; i--) {
		if (c[i] != 0) {
			result1[j] = i;
			result2[j] = c[i];
			j++;
			nozero++;
		}
	}
	printf("%d", nozero);
	for (i = 0; result2[i] != 0 && i < 128; i++)
		printf(" %d %.1lf", result1[i], result2[i]);
	printf("\n");
	return 0;
}
