#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int w, s, i;
} record;

int comp(const void *a, const void *b)
{
	record *r1, *r2;
	r1 = (record *)a, r2 = (record *)b;
	if (r1->w != r2->w)
		return r1->w - r2->w;
	return r2->s - r1->s;
}

int main()
{
	int w, s, i, j, k, n, m[1024], index, max;
	record rec[1024];

	for (n = 0; scanf("%d %d", &w, &s) != EOF; n++)
			rec[n].w = w, rec[n].s = s, rec[n].i = n + 1, m[n] = 1;
	qsort(rec, n, sizeof(record), comp);
	for (i = n - 1; i >= 1; i--)
		for (j = i - 1; j >= 0; j--)
			if (rec[j].w < rec[i].w && rec[j].s > rec[i].s)
				if (m[i] + 1 > m[j])
					m[j] = m[i] + 1;
	for (i = 0, max = 0; i < n; i++)
		if (m[i] > max) {
			max = m[i];
			index = i;
		}
	printf("%d\n", max);
	printf("%d\n", rec[index].i);
	for (i = index + 1, max--; i < n && max; i++)
		if (rec[i].w > rec[index].w && rec[i].s < rec[index].s && m[i] == max) {
			printf("%d\n", rec[i].i);
			index = i, max--;
		}
	return 0;
}

