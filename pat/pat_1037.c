#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int n, m, a[100001], b[100001], i, j;
	long long ans = 0ll;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%d", &b[i]);
	qsort(a, n, sizeof(int), comp), qsort(b, m, sizeof(int), comp);
	for (i = 0; a[i] > 0 && b[i] > 0; i++)
		ans += a[i] * b[i];
	for (i = n - 1, j = m - 1; a[i] < 0 && b[j] < 0; i--, j--)
		ans += a[i] * b[j];
	printf("%lld", ans);
	return 0;
}

