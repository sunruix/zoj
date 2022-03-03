#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[16];
	int par, pri, n;
} msg;

typedef struct {
	msg *array[60000];
	int size;
} heap;

void insert(msg *m, heap *h)
{
	int i, j;
	for (i = ++h->size; i > 1; i = j) {
		j = i / 2;
		if (m->pri < h->array[j]->pri)
			h->array[i] = h->array[j];
		else
			break;
	}
	h->array[i] = m;
}

void delete(heap * h)
{
	int i, j;
	msg *first, *last;
	if (h->size == 0) {
		printf("EMPTY QUEUE!\n");
		return;
	}
	first = h->array[1];
	last = h->array[h->size--];
	for (i = 1; 2 * i <= h->size; i = j) {
		j = 2 * i;
		if (j < h->size && (h->array[j]->pri > h->array[j + 1]->pri ||
					(h->array[j]->pri == h->array[j + 1]->pri &&
					 h->array[j]->n > h->array[j + 1]->n)))
			j++;
		if (h->array[j]->pri < last->pri || (h->array[j]->pri == last->pri && h->array[j]->n < last->n))
			h->array[i] = h->array[j];
		else
			break;
	}
	h->array[i] = last;
	printf("%s %d\n", first->name, first->par);
}

int main()
{
	int n = 0;
	char cmd[8];
	heap h;
	msg *temp;

	h.size = 0;
	while (scanf("%s", cmd) != EOF) {
		if (!strcmp(cmd, "GET"))
			delete(&h);
		else {
			temp = malloc(sizeof(msg));
			scanf("%s %d %d", temp->name, &temp->par, &temp->pri);
			temp->n = n++;
			insert(temp, &h);
		}
	}
	return 0;
}
