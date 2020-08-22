#include <stdio.h>
#include <string.h>

typedef struct {
	int v, w, l;
} edge;

edge E[15001];
int N, M, s[1024], ans[15001];

int find(int x)
{
	if (s[x] <= 0)
		return x;
	return s[x] = find(s[x]);
}

void setunion(int root1, int root2)
{
	if (s[root1] < s[root2])
		s[root2] = root1;
	else if (s[root2] < s[root1])
		s[root1] = root2;
	else {
		s[root2] = root1;
		s[root1]--;
	}
}

int comp(const void *a, const void *b)
{
	edge *n1, *n2;
	n1 = (edge *)a, n2 = (edge *)b;
	return n1->l > n2->l;
}

int main()
{
	int i, j, root1, root2, count, max;

	while (scanf("%d %d", &N, &M) != EOF) {
		memset(s, 0, sizeof(s));
		for (i = 0; i < M; i++)
			scanf("%d %d %d", &E[i].v, &E[i].w, &E[i].l);
		qsort(E, M, sizeof(edge), comp);
		for (i = 0, count = 0, max = 0; i < M && count < N - 1; i++) {
			root1 = find(E[i].v), root2 = find(E[i].w);
			if (root1 == root2)
				continue;
			setunion(root1, root2);
			ans[count++] = i;
			if (E[i].l > max)
				max = E[i].l;
		}
		printf("%d\n", max);
		printf("%d\n", count);
		for (i = 0; i < count; i++)
			printf("%d %d\n", E[ans[i]].v, E[ans[i]].w);
	}
	return 0;
}
