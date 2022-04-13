#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[9];
	int age, worth;
} record;

int comp1(const void *a, const void *b)
{
	record *pa = (record *)a, *pb = (record *)b;

	if (pa->worth != pb->worth)
		return pb->worth - pa->worth;
	if (pa->age != pb->age)
		return pa->age - pb->age;
	return strcmp(pa->name, pb->name);
}

int comp2(const void *a, const void *b)
{
	record *pa = (record *)a, *pb = (record *)b;

	if (pa->age != pb->age)
		return pa->age - pb->age;
	if (pa->worth != pb->worth)
		return pb->worth - pa->worth;
	return strcmp(pa->name, pb->name);
}

int main()
{
	int n, m, i, j, k, l, up, low;
	record a[100001];

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s %d %d", &a[i].name, &a[i].age, &a[i].worth);
	qsort(a, n, sizeof(record), comp2);
	for (i = 1; i < n; i++) {
		for (j = 1; i < n && j < 100 && a[i].age == a[i - 1].age; i++, j++);
		for (; i < n && a[i].age == a[i - 1].age; i++)
			a[i].worth = -10000000;
	}
	qsort(a, n, sizeof(record), comp1);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &k, &low, &up);
		printf("Case #%d:\n", i);
		for (l = k, j = 0; j < n && a[j].worth != -10000000 && k; j++)
			if (a[j].age >= low && a[j].age <= up)
				printf("%s %d %d\n", a[j].name, a[j].age, a[j].worth), k--;
		if (l == k)
			printf("None\n");
	}
	return 0;
}