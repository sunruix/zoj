#include <stdio.h>
#define MAX 0x7ffffff

typedef struct {
	int a, b, c;
} edge;

int Bellman_Ford(int n, int m, int *d, edge *E)
{
	int i, j;

	for (d[0] = 0, i = 1; i <= n; i++)
		for (j = 0; j < m; j++)
			if (d[E[j].b] > d[E[j].a] + E[j].c)
				d[E[j].b] = d[E[j].a] + E[j].c;
	for (j = 0; j < m; j++)
		if (d[E[j].b] > d[E[j].a] + E[j].c)
			return 0;
	return 1;
}

int main()
{
	int n, m, i, a, b, c, ans, d[128];
	char op[4];
	edge E[128];

	while (scanf("%d %d", &n, &m) != EOF && n) {
		for (i = 0; i < m; i++) {
			scanf("%d %d %s %d", &a, &b, op, &c);
				op[0] == 'g' ? (E[i].a = a + b, E[i].b = a - 1, E[i].c = -c - 1) :
				(E[i].a = a - 1, E[i].b = a + b, E[i].c = c - 1);
		}
		for (i = 0; i <= n; d[i++] = MAX);
		ans = Bellman_Ford(n, m, d, E);
		printf("%s\n", ans ? "lamentable kingdom" : "successful conspiracy");
	}
	return 0;
}
