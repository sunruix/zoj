#include <stdio.h>

int main()
{
	int t, n, d, a[100001], i, j;

	a[0] = 0;
	for (i = 1, d = 1; d <= 10000; i++)
		for (j = 0; j < i && d <= 10000; j++, d++)
			a[d] = a[d - 1] + i;
	scanf("%d", &t);
	while (t--) {
		while (scanf("%d", &n) != EOF && n)
			printf("%d %d\n", n, a[n]);
		if (t)
			printf("\n");
	}
	return 0;
}
