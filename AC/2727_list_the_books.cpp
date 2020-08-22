#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[128];
	int year, price;
} record;

int comp_name(const void *a, const void *b)
{
	record *pa, *pb;

	pa = (record *)a, pb = (record *)b;
	if (strcmp(pa->name, pb->name))
		return strcmp(pa->name, pb->name);
	else if (pa->year != pb->year)
		return pa->year - pb->year;
	else
		return pa->price - pb->price;
}

int comp_year(const void *a, const void *b)
{
	record *pa, *pb;

	pa = (record *)a, pb = (record *)b;
	if (pa->year != pb->year)
		return pa->year - pb->year;
	else if (strcmp(pa->name, pb->name))
		return strcmp(pa->name, pb->name);
	else
		return pa->price - pb->price;
}

int comp_price(const void *a, const void *b)
{
	record *pa, *pb;

	pa = (record *)a, pb = (record *)b;
	if (pa->price != pb->price)
		return pa->price - pb->price;
	else if (strcmp(pa->name, pb->name))
		return strcmp(pa->name, pb->name);
	else
		return pa->year - pb->year;
}

int main()
{
	int n, i, count = 0;
	char s[8];
	record rec[128];

	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; i++)
			scanf("%s %d %d", rec[i].name, &rec[i].year, &rec[i].price);
		scanf("%s", s);
		if (!strcmp(s, "Name"))
			qsort(rec, n, sizeof(record), comp_name);
		else if (!strcmp(s, "Year"))
			qsort(rec, n, sizeof(record), comp_year);
		else
			qsort(rec, n, sizeof(record), comp_price);
		if (count++)
			printf("\n");
		for (i = 0; i < n; i++)
			printf("%s %d %d\n", rec[i].name, rec[i].year, rec[i].price);
	}
	return 0;
}