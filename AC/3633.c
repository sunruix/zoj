#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int tip, pos;
} record;

int comp(const void *a, const void *b)
{
	if (((record *)a)->tip != ((record *)b)->tip)
		return ((record *)a)->tip - ((record *)b)->tip;
	return ((record *)b)->pos - ((record *)a)->pos;
}

int n, m, i, j, k, a[500005], ans;
record rec[500005], temp, *p;

int main()
{
	freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]), rec[i].tip = a[i], rec[i].pos = i;
		qsort(rec + 1, n, sizeof(record), comp);
		scanf("%d", &m);
		while (m--) {
			scanf("%d %d", &i, &j);
			for (ans = 0, k = j; k >= i && k > ans - 1; k--) {
				temp.pos = k, temp.tip = a[k];
				p = (record *)bsearch(&temp, rec + 1, n, sizeof(record), comp);
				if ((p + 1)->tip == a[k] && (p + 1)->pos >= i && (p + 1)->pos > ans)
					ans = (p + 1)->pos;
			}
			ans ? printf("%d\n", a[ans]) : printf("OK\n");
		}
		printf("\n");
	}
	return 0;
}