#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int t, n, i, a[1024], b, ans;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		qsort(a + 1, n, sizeof(int), comp);
		for (ans = 0, i = 1; i <= n; i++) {
			b = i * a[i];
			if (ans < b)
				ans = b;
		}
		printf("%d\n", ans);
	}
	return 0;
}