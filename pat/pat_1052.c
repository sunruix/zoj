#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key, add;
} node;

int comp(const void *a, const void *b)
{
	return ((node *)a)->key - ((node *)b)->key;
}

int n, i, j, head, add, key, next;
node l1[100001], l2[100001];

int main()
{
	scanf("%d %d", &n, &head);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &add, &key, &next);
		l1[add].key = key, l1[add].add = next;
	}
	for (i = head, j = 0; i > 0; i = l1[i].add, j++)
		l2[j].add = i, l2[j].key = l1[i].key;
	if (j > 0) {
		qsort(l2, j, sizeof(node), comp);
		for (printf("%d %05d\n", j, l2[0].add), i = 0; i < j - 1; i++)
			printf("%05d %d %05d\n", l2[i].add, l2[i].key, l2[i + 1].add);
		printf("%05d %d -1\n", l2[i].add, l2[i].key);
	}
	else
		printf("0 -1\n");
	return 0;
}
