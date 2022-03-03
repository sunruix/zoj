#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int in, out;
} ring;

int comp(const void *a, const void *b)
{
	return ((ring *)a)->out - ((ring *)b)->out;
}

int main()
{
	int n, i, j, ans;
	ring a[10001];

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d %d", &a[i].in, &a[i].out);
		qsort(a, n, sizeof(ring), comp);
		for (i = 0, j = a[0].out, ans = 1; i < n; i++)
			if (a[i].in >= j)
				ans++, j = a[i].out;
		printf("%d\n", n - ans);
	}
	return 0;
}