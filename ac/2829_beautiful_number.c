#include <stdio.h>

int main()
{
	int i, j, v3, v5, n, a[100001];
	
	for (i = j = 1, n = a[0] = 0; n < 100000; n++) {
		while (3 * i <= a[n]) i++;
		while (5 * j <= a[n]) j++;
		v3 = 3 * i, v5 = 5 * j;
		a[n + 1] = v3 < v5 ? v3 : v5;
	}
	while (scanf("%d", &n) != EOF)
		printf("%d\n", a[n]);
	return 0;
}