#include <stdio.h>
#include <string.h>

typedef struct {
	int a, b, c;
} edge;

int Bellman_Ford(int n, int m, int *d, edge *E)
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (d[E[j].a] < d[E[j].b] + E[j].c)
				d[E[j].a] = d[E[j].b] + E[j].c;
	for (j = 0; j < m; j++)
		if (d[E[j].a] < d[E[j].b] + E[j].c)
			return 0;
	return 1;
}

int main()
{
	int c = 1, n, m, i, a, b, t[1024], d[1024];
	char s[4];
	edge E[1024];

	while (scanf("%d", &n) != EOF && n) {
		for (i = 1; i <= n; i++)
			scanf("%d", &t[i]);
		m = 0;
		while (scanf("%s", s) != EOF && strcmp(s, "#")) {
			scanf("%d %d", &a, &b);
			E[m].a = a, E[m].b = b;
			s[0] == 'F' && s[2] == 'S' ? E[m++].c = -t[a] : 0;
			s[0] == 'F' && s[2] == 'F' ? E[m++].c = t[b] - t[a] : 0;
			s[0] == 'S' && s[2] == 'F' ? E[m++].c = t[b] : 0;
			s[0] == 'S' && s[2] == 'S' ? E[m++].c = 0 : 0;
		}
		memset(d, 0, sizeof(d));
		printf("Case %d:\n", c++);
		if (!Bellman_Ford(n, m, d, E))
			printf("impossible\n");
		else
			for (i = 1; i <= n; i++)
				printf("%d %d\n", i, d[i]);
		printf("\n");
	}
	return 0;
}

			