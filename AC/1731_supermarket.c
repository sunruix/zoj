#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
	int p, d;
} record;

int comp(const void *a, const void *b)
{
	return ((record *)a)->d - ((record *)b)->d;
}

int main()
{
	int n, i, j, ans, dp[10001];
	record a[10001];

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d %d", &a[i].p, &a[i].d);
		qsort(a, n, sizeof(record), comp);
		memset(dp, 0, sizeof(dp));
		for (ans = i = 0; i < n; i++)
			for (j = a[i].d; j > 0; j--)
				dp[j] = max(dp[j], dp[j - 1] + a[i].p), ans = max(ans, dp[j]);
		printf("%d\n", ans);
	}
	return 0;
}