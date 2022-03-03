#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char f[32];
	int in;
} record;

int comp(const void *a, const void *b)
{
	record *pa = (record *)a, *pb = (record *)b;

	return strcmp(pa->f, pb->f);
}

int main()
{
	int n, m, i, j, k, p, count = 0;
	char s[32];
	record rec[1024];

	while (scanf("%d", &n) != EOF) {
		memset(rec, 0, sizeof(rec));
		for (p = i = 0; i < n; i++) {
			scanf("%s", s);
			for (j = 0; j < p && strcmp(s, rec[j].f); j++);
			if (j == p)
				strcpy(rec[p++].f, s);
			scanf("%d", &m);
			for (j = 0; j < m; j++) {
				scanf("%s", s);
				for (k = 0; k < p && strcmp(s, rec[k].f); k++);
				if (k == p)
					strcpy(rec[p++].f, s);
				rec[k].in++;
			}
		}
		qsort(rec, p, sizeof(record), comp);
		if (count++)
			printf("\n");
		for (i = 0; i < p; i++)
			if (!rec[i].in)
				printf("%s\n", rec[i].f);
	}
	return 0;
}