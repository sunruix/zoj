#include <stdio.h>

typedef struct {
	int v, w, weight;
} edge;

int find(int x, int s[])
{
	if (s[x] == 0)
		return x;
	else
		return s[x] = find (s[x], s);
}

void setunion(int root1, int root2, int s[])
{
	if (root1 < root2)
		s[root2] = root1;
	else {
		if (root1 == root2)
			root2 -= 1;
		s[root1] = root2;
	}
}

int comp(const void *a, const void *b)
{
	return ((edge *)a)->weight - ((edge *)b)->weight;
}

edge E[1000001];
int main()
{
	int n, m, s[100001], root1, root2, i, count;
	freopen("input1", "r" ,stdin);
	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &E[i].v, &E[i].w, &E[i].weight);
			s[i] = 0;
		}
		qsort(E, m, sizeof(edge), comp);
		for (i = count = 0; i < m && count < n - 1; i++) {
			root1 = find(E[i].v, s);
			root2 = find(E[i].w, s);
			if (root1 != root2) {
				setunion(root1, root2, s);
				count++;
			}
			printf("%d\n", E[i].weight);
		}
	}
	return 0;
}
