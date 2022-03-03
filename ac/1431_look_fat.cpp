#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[32];
	int day, weight;
} record;

int comp(const void *a, const void *b)
{
	return ((record *)b)->weight - ((record *)a)->weight;
}

int main()
{
	int i, j, n, count;
	char s[32];
	record rec[16];

	count = 0;
	while (scanf("%s", s) != EOF) {
		for (i = 0; ; i++) {
			scanf("%s", s);
			if (!strcmp(s, "END"))
				break;
			strcpy(rec[i].name, s);
			scanf("%d %d", &rec[i].day, &rec[i].weight);
			rec[i].weight -= rec[i].day;
		}
		if (count++)
			printf("\n");
		qsort(rec, i, sizeof(record), comp);
		for (j = 0; j < i; j++)
			printf("%s\n", rec[j].name);
	}
	return 0;
}