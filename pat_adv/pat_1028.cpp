#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id, score;
	char name[16];
} record;

int comp1(const void *a, const void *b)
{
	record *pa = (record *)a, *pb = (record *)b;

	return pa->id - pb->id;
}

int comp2(const void *a, const void *b)
{
	record *pa = (record *)a, *pb = (record *)b;
	int result;

	if (result = strcmp(pa->name, pb->name))
		return result;
	return pa->id - pb->id;
}

int comp3(const void *a, const void *b)
{
	record *pa = (record *)a, *pb = (record *)b;
	int result;

	if (result = pa->score - pb->score)
		return result;
	return pa->id - pb->id;
}

record rec[100000];

int main()
{
	int n, q, i;

	scanf("%d %d", &n, &q);
	for (i = 0; i < n; i++)
		scanf("%d %s %d", &rec[i].id, &rec[i].name, &rec[i].score);
	if (q == 1)
		qsort(rec, n, sizeof(record), comp1);
	else if (q == 2)
		qsort(rec, n, sizeof(record), comp2);
	else
		qsort(rec, n, sizeof(record), comp3);
	for (i = 0; i < n; i++)
		printf("%.06d %s %d\n", rec[i].id, rec[i].name, rec[i].score);
	return 0;
}