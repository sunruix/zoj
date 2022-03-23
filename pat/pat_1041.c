#include <stdio.h>

int n, i, j, a[10001], ans;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &j);
		a[j] = a[j] ? -i : i;
	}
	for (j = n + 1, i = 1; i <= 10000; i++)
		if (a[i] > 0 && j > a[i])
			j = a[i], ans = i;
	ans ? printf("%d", ans) : printf("None");
	return 0;
}
