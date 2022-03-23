#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, k, nozero = 0;
	double f, a[1024];

	memset(a, 0, sizeof(a));
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d", &j);
		scanf("%lf", &a[j]);
	}
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d", &j);
		scanf("%lf", &f);
		a[j] += f;
	}
	for (i = 0; i < 1024; i++)
		if (a[i] != 0)
			nozero++;
	printf("%d", nozero);
	for (i = 1023; i >= 0; i--)
		if (a[i] != 0)
			printf(" %d %.1f", i, a[i]);
	printf("\n");
	return 0;
}
