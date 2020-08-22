#include <stdio.h>

void op(int a[], int b[], int n, int p, int c)
{
	int i, j, k;

	for (i = 0, j = 0; i < p - 1; i++, j++)
		b[j] = a[i];
	for (i = j, k = 0; k < c; i++, k++)
		a[k] = a[i];
	for (i = k, j = 0; j < p - 1; i++, j++)
		a[i] = b[j];
}

int main()
{
	int n, r, p, c, a[64], b[64], i;
	while (scanf("%d %d", &n, &r) != EOF && n && r) {
		for (i = 0; i < n; i++)
			a[i] = n - i;
		while (r--) {
			scanf("%d %d", &p, &c);
			op(a, b, n, p, c);
		}
		printf("%d\n", a[0]);
	}
	return 0;
}