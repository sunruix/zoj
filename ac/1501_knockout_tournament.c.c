#include <stdio.h>

void high(int i, int *a, int *hi, int n)
{
	if (i << 1 >= 1 << (n + 1))
		return;
	a[i << 1] == a[i] ? (hi[a[(i << 1) + 1]] = hi[a[i]] + 1, hi[a[i << 1]] = hi[a[i]]) :
		(hi[a[i << 1]] = hi[a[i]] + 1, hi[a[(i << 1) + 1]] = hi[a[i]]);
	high(i << 1, a, hi, n), high((i << 1) + 1, a, hi, n);
}

int main()
{
	int n, i, j, k, a[256], hi[256], lo[256], t = 0;

	while (scanf("%d", &n) != EOF && n) {
		for (i = n - 1; i >= 0; i--)
			for (j = 1 << i; j < 1 << (i + 1); j++)
				scanf("%d", &a[j]);
		for (i = 1 << n; i < 1 << (n + 1); i++)
			a[i] = i - (1 << n) + 1;
		for (i = 1 << n; i < 1 << (n + 1); i++) {
			j = i, k = 0;
			while (j > 1 && a[j >> 1] == a[j])
				j >>= 1, k++;
			lo[a[i]] = j == 1 ? 1 : ((1 << n) - (1  << k) + 1);
		}
		hi[a[1]] = 1, high(1, a, hi, n);
		scanf("%d", &i);
		if (t++)
			printf("\n");
		while (i--) {
			scanf("%d", &k);
			printf("Player %d can be ranked as high as %d or as low as %d.\n", k, hi[k], lo[k]);
		}
	}
	return 0;
}

