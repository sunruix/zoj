#include <stdio.h>

typedef struct {
	int w, l, h;
} box;

int comp(const void *a, const void *b)
{
	box *pa, *pb;

	pa = (box *)a, pb = (box *)b;
	if (pa->w != pb->w)
		return pb->w - pa->w;
	return pb->l - pa->l;
}

int main()
{
	int n, i, j, k, w, l, h, m[128], max, temp, count;
	box a[128];

	count = 1;
	while (scanf("%d", &n) != EOF && n) {
		i = 0;
		while (n--) {
			scanf("%d %d %d", &w, &l, &h);
			a[i].h = w, a[i].w = l < h ? l : h, a[i].l = l > h ? l : h;
			a[i + 1].h = l, a[i + 1].w = w < h ? w : h, a[i + 1].l = w > h ? w : h;
			a[i + 2].h = h, a[i + 2].w = w < l ? w : l, a[i + 2].l = w > l ? w : l;
			i += 3;
		}
		n = i;
		qsort(a, n, sizeof(box), comp);
		for (i = max = 0; i < n; i++) {
			for (j = temp = 0; j < i; j++)
				if (a[j].w > a[i].w && a[j].l > a[i].l && temp < m[j])
					temp = m[j];
			m[i] = temp + a[i].h;
			max = max > m[i] ? max : m[i];
		}
		printf("Case %d: maximum height = %d\n", count++, max);
	}
	return 0;
}