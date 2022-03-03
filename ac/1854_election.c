#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[128], party[128];
	int count;
} record;

int comp(const void *a, const void *b)
{
	record *pa = (record *)a, *pb = (record *)b;

	return strcmp(pa->name, pb->name);
}

int main()
{
	int n, m, i, max, pos, change;
	char name[128];
	record rec[32], *p;

	while (scanf("%d\n", &n) != EOF) {
		for (i = 0; i < n; i++)
			gets(rec[i].name), gets(rec[i].party), rec[i].count = 0;
		qsort(rec, n, sizeof(record), comp);
		scanf("%d\n", &m);
		while (m--) {
			gets(name);
			if ((p = bsearch(name, rec, n, sizeof(record), comp)) != NULL)
				p->count++;
		}
		for (max = rec[0].count, pos = 0, change = 1, i = 1; i < n; i++)
			if (rec[i].count > max)
				change = 1, max = rec[i].count, pos = i;
			else if (rec[i].count == max)
				change = 0;
		if (change)
			printf("%s\n", rec[pos].party);
		else
			printf("tie\n");
	}
	return 0;
}