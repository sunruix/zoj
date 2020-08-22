#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 1024

typedef struct {
	int array[size], head, tail;
} queue;

void enqueue(queue *q, int x)
{
	q->array[q->tail] = x;
	q->tail = (q->tail + 1) % size;
}

void dequeue(queue *q)
{
	printf("%d\n", q->array[q->head]);
	q->head = (q->head + 1) % size;
}

queue q[1024], Q;

int main()
{
	int ca = 1, t, n, i, j, team[1000000];
	char s[32];

	while (scanf("%d", &t) != EOF && t) {
		Q.head = Q.tail = 0, printf("Scenario #%d\n", ca++);
		for (i = 0; i < t; i++) {
			scanf("%d", &n), q[i].head = q[i].tail = 0;
			while (n--)
				scanf("%d", &j), team[j] = i;
		}
		while (scanf("%s", s) != EOF && strcmp(s, "STOP")) {
			if (!strcmp(s, "ENQUEUE")) {
				scanf("%d", &j), i = team[j];
				if (q[i].head == q[i].tail)
					enqueue(&Q, i);
				enqueue(&(q[i]), j);
			}
			else {
				i = Q.array[Q.head], dequeue(&(q[i]));
				if (q[i].head == q[i].tail)
					Q.head = (Q.head + 1) % 1024;
			}
		}
		printf("\n");
	}
	return 0;
}
