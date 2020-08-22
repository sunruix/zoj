#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int l, r;
} page;

int comp(const void *a, const void *b)
{
	page *pa, *pb;

	pa = (page*)a, pb = (page *)b;
	return pa->l - pb->l;
}

int main()
{
	int t, n, cl, cr, ans, flag, i;
	page pages[5005];

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d %d", &pages[i].l, &pages[i].r);
		qsort(pages, n, sizeof(page), comp);
		for (i = 0, cl = cr = ans = flag = 0; i < n; i++) {
			if (pages[i].l <= cl + 1 && pages[i].r > cr) {
				cr = pages[i].r;
				if (!flag)
					ans++, flag = 1;
			}
			else if (pages[i].l > cl + 1)
				cl = cr, flag = 0, i--;
		}
		printf("%d\n", ans);
	}
	return 0;
}