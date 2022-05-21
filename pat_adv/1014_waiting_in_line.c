#include <stdio.h>
#include <stdlib.h>

typedef struct QUEUE {
	int array[16];
	int size, cap;
	int head, tail;
} *queue;

void enqueue(int x, queue Q)
{
	Q->array[Q->tail] = x;
	Q->tail = (Q->tail + 1) % Q->cap;
	Q->size++;
}

int dequeue(queue Q)
{
	int x;
	
	x = Q->array[Q->head];
	Q->head = (Q->head + 1) % Q->cap;
	Q->size--;
	return x;
}

int N, M, K, Q, t, T[1024], lefttime[20], ask[1024];
int start[1024], end[1024];
int pos = 1, shst, p_shst;
queue window[20];

int main()
{
	int i, j, k, left;
	FILE *fd;

	fd = fopen("input", "r");
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	for (i = 1; i <= K; i++) {
		scanf("%d", &T[i]);
		start[i] = 540;
		end[i] = 541;
	}
	for (i = 0; i < Q; i++)
		scanf("%d", &ask[i]);
	for (i = 0; i < N; i++) {
		window[i] = malloc(sizeof(struct QUEUE));
		window[i]->cap = M;
		window[i]->size = 0;
		window[i]->head = window[i]->tail = 0;
	}
	for (t = 0; t <= 540; t++) {
		//enter line
		for (i = pos; i <= K; i++) {
			shst = M; p_shst = -1;
			for (j = 0; j < N; j++) {
				if (shst > window[j]->size) {
					shst = window[j]->size;
					p_shst = j;
				}
			}
			if (p_shst >= 0) {
				enqueue(i, window[p_shst]);
				if (window[p_shst]->size == 1) {
					lefttime[p_shst] = T[i];
					start[i] = t;
					end[i] = t + T[i];
				}
				pos++;
			}
			else
				break;
		}
		//serve
		for (i = 0; i < N; i++) {
			if (window[i]->size <= 0)
				continue;
			if (--lefttime[i] == 0) {
				dequeue(window[i]);
				if (window[i]->size) {
					lefttime[i] = T[window[i]->array[window[i]->head]];
					start[window[i]->array[window[i]->head]] = t + 1;
					end[window[i]->array[window[i]->head]] =
						T[window[i]->array[window[i]->head]] +
						start[window[i]->array[window[i]->head]];
				}
			}
		}
	}
	for (i = 0; i < Q; i++) {
		if (start[ask[i]] < 540)
			printf("%02d:%02d\n", end[ask[i]] / 60 + 8, end[ask[i]] % 60);
		else
			printf("Sorry\n");
	}
	return 0;
}
