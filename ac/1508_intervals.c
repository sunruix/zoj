#include <stdio.h>
#include <string.h>

typedef struct {
	int a, b, c;
} edge;

int Bellman_Ford(int n, int *d, edge *E, int min, int max)
{
	int i, j, k, over = 0;

	for (i = min; i <= max && !over; i++) {
		over = 1;
		for (j = 0; j < n; j++)
			if (d[E[j].a] + E[j].c > d[E[j].b])
				d[E[j].b] = d[E[j].a] + E[j].c, over = 0;
		for (k = min; k < max; k++)
			d[k] > d[k + 1] ? (d[k + 1] = d[k]), (over = 0) : 0;
		for (k = max; k > min; k--)
			d[k] > d[k - 1]  + 1 ? (d[k - 1] = d[k] - 1), (over = 0) : 0;
	}
	return d[max];
}

int main()
{
	int n, i, min, max, d[50005];
	edge E[50005];

	while (scanf("%d", &n) != EOF) {
		memset(d, 0, sizeof(d)), max = 0, min = 50005;
		for (i = 0; i < n; i++) {
			scanf("%d %d %d", &E[i].a, &E[i].b, &E[i].c);
			E[i].b++;
			E[i].a < min ? min = E[i].a : 0;
			E[i].b > max ? max = E[i].b : 0;
		}
		printf("%d\n", Bellman_Ford(n, d, E, min, max));
	}
	return 0;
}
