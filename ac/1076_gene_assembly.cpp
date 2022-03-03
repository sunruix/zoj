#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int l, r, n;
} exon;

int comp(const void *a, const void *b)
{
	exon *pa, *pb;

	pa = (exon *)a, pb = (exon *)b;
	if (pa->l != pb->l)
		return pa->l - pb->l;
	return pa->r - pb->r;
}

int main()
{
	int n, i, j, m[1024], next[1024], max, maxp;
	exon E[1024];

	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; i++)
			scanf("%d %d", &E[i].l, &E[i].r), E[i].n = i + 1;
		qsort(E, n, sizeof(exon), comp);
		memset(m, 0, sizeof(m));
		for (i = n - 1, max = 0; i >= 1; i--)
			for (j = i - 1; j >= 0; j--)
				if (E[j].r < E[i].l)
					if (m[j] < m[i] + 1) {
						m[j] = m[i] + 1, next[j] = i;
					if (max < m[j])
						max = m[j], maxp = j;
					}
		for (i = 0, j = maxp; i < max; i++) {
			printf("%d ", E[j].n);
			j = next[j];
		}
		printf("%d\n", E[j].n);
	}
	return 0;
}