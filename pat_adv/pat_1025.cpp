#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char id[16];
	int score, location, rank;
} record;

int comp(const void *a, const void *b)
{
	record *aa, *bb;
	aa = (record *)a, bb = (record *)b;
	if (bb->score != aa->score)
		return bb->score - aa->score;
	else
		return strcmp(aa->id, bb->id);
}

record rec[300 * 128];

int main()
{
	int n, a[128], i, j, k, last;

	scanf("%d", &n);
	a[0] = 0;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
		for (j = a[i - 1]; j < a[i]; j++) {
			scanf("%s %d", rec[j].id, &rec[j].score);
			rec[j].location = i;
		}
		qsort(rec + a[i - 1], a[i] - a[i - 1], sizeof(record), comp);
		rec[a[i - 1]].rank = 1;
		for (j = a[i - 1] + 1, k = 2; j < a[i]; j++, k++) {
			if (rec[j].score == rec[j - 1].score)
				rec[j].rank = rec[j - 1].rank;
			else
				rec[j].rank = k;
		}
	}
	qsort(rec, a[n], sizeof(record), comp);
	printf("%d\n", a[n]);
	printf("%s %d %d %d\n", rec[0].id, 1, rec[0].location, rec[0].rank);
	for (i = 1, last = 1; i < a[n]; i++) {
		if (rec[i].score == rec[i - 1].score)
			printf("%s %d %d %d\n", rec[i].id, last, rec[i].location, rec[i].rank);
		else {
			printf("%s %d %d %d\n", rec[i].id, i + 1, rec[i].location, rec[i].rank);
			last = i + 1;
		}
	}
	return 0;
}
