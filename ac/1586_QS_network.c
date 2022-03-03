#include <stdio.h>
#include <string.h>

typedef struct {
	int v, w, l;
} edge;
edge E[1024 * 1024];
int t, n, s[1024];

int find(int x)
{
	if (s[x] <= 0)
		return x;
	return s[x] = find(s[x]);
}

int comp(const void *a, const void *b)
{
	edge *n1, *n2;
	n1 = (edge *)a, n2 = (edge *)b;
	return n1->l > n2->l;
}

int main()
{
	int i, j, k, sum, count, apt[1024], root1, root2;
	freopen("input", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(s, 0, sizeof(s));
		scanf("%d", &n);
		sum = count = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d", &apt[i]);
		}
		k = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				E[k].v = i, E[k].w = j;
				scanf("%d", &E[k].l);
				E[k].l = E[k].l + apt[E[k].v] + apt[E[k].w];
				k++;
			}
		}
		qsort(E, k, sizeof(edge), comp);
		for (i = 0; i < k && count < n - 1; i++) {
			root1 = find(E[i].v), root2 = find(E[i].w);
			if (root1 == root2)
				continue;
			s[root1] = root2;
			sum += E[i].l;
			count++;
		}
		printf("%d\n", sum);
	}
	return 0;
}

