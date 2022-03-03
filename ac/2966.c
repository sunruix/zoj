#include <stdio.h>
#include <string.h>

typedef struct {
	int w, v, l;
} edge;
edge e[512 * 256];
int I, N, E, s[512];

int find (int x)
{
	if (s[x] < 0)
		return x;
	return s[x] = find(s[x]);
}

void setunion(int root1, int root2)
{
	if (s[root1] < s[root2])
		s[root2] = root1;
	else {
		if (s[root1] == s[root2])
			s[root2]--;
		s[root1] = root2;
	}
}

int comp(const void *a, const void *b)
{
	return ((edge *)a)->l > ((edge *)b)->l;
}

int main()
{
	int i, j, root1, root2, sum, count;

	scanf("%d", &I);
	while (I--) {
		scanf("%d %d", &N, &E);
		memset(s, -1, sizeof(s));
		for (i = 0; i < E; i++)
			scanf("%d %d %d", &e[i].v, &e[i].w, &e[i].l);
		qsort(e, E, sizeof(edge), comp);
		for (i = 0, count = 0, sum = 0; i < E && count < N - 1; i++) {
			root1 = find(e[i].v), root2 = find(e[i].w);
			if (root1 == root2)
				continue;
			sum += e[i].l;
			setunion(root1, root2);
			count++;
		}
		printf("%d\n", sum);
	}
	return 0;
}
