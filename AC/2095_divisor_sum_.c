#include <stdio.h>

int a[500001];
int main()
{
	int n, i, j, k;
	for (i = 1; i <= 500000; i++) {
		for (j = 2, k = i / 2; j <= k; j++)
			if (!(i % j)) {
				a[i] = a[i] + j + i / j;
				k = i / j - 1;
			}
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &i);
		printf("%d\n", a[i] + 1);
	}
	return 0;
}
