#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ID[16];
	char in_time[16];
	char out_time[16];
} record;

int cmp_in(const void *p1, const void *p2)
{
	return strcmp(((record *)p1)->in_time, ((record *)p2)->in_time);
}

int cmp_out(const void *p1, const void *p2)
{
	return strcmp(((record *)p2)->out_time, ((record *)p1)->out_time);
}

int main()
{
	int M, i;
	record rec[128];
	scanf("%d", &M);
	for (i = 0; i < M; i++)
		scanf("%s %s %s", rec[i].ID, rec[i].in_time, rec[i].out_time);
	qsort(rec, M, sizeof(record), cmp_in);
	printf("%s ", rec[0].ID);
	qsort(rec, M, sizeof(record), cmp_out);
	printf("%s\n", rec[0].ID);
	return 0;
}
