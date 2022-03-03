#include <stdio.h>
#include <stdlib.h>

typedef struct heaprecord {
	int array[65536];
	int size;
} *heap;

void insert(int x, heap h) {
	int i, j;
	for (i = h->size++; i > 1; i /= 2) {
		if (h->array[i / 2] < x)
			h->array[i] = h->array[i / 2];
		else
			break;
	}
	h->array[i] = x;
}

int main()
{
	int N, i;
	heap h;

	h = malloc(sizeof(struct heaprecord));
	while (scanf("%d", &N) != EOF) {
		h->array[1] = 1, h->size = 1;
		for (i = 2; i <= N; i++)
			insert(i, h);
		h->array[N] = 1;
		for (i = 1; i < N; i++)
			printf("%d ", h->array[i]);
		printf("1\n");
	}
	return 0;
}
