#include <stdio.h>

char b[64000000];

int main()
{
	int i, n, a[500001];

	for (a[0] = 0, b[0] = 1, i = 1; i <= 500000; i++) {
		if ((a[i] = a[i - 1] - i) <= 0 || b[a[i]])
			a[i] = a[i - 1] + i;
		b[a[i]] = 1;
	}
	while (scanf("%d", &n) != EOF && n >= 0)
		printf("%d\n", a[n]);
	return 0;
}