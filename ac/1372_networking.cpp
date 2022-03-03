#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int v, w, l;
} edge;

int comp(const void *a, const void *b)
{
	return ((edge *)a)->l - ((edge *)b)->l;
}

int find(int x, int s[])
{
	if (s[x] <= 0)
		return x;
	return s[x] = find(s[x], s);
}

void setunion(int root1, int root2, int s[])
{
	if (s[root1] < s[root2])
		s[root2] = root1;
	else {
		if (s[root1] == s[root2])
			s[root2]--;
		s[root1] = root2;
	}
}

int main()
{
	int m, n, i, j, v, w, l, root1, root2, s[64], ans;
	edge E[32768];

	while (scanf("%d %d", &m, &n) != EOF && m) {
		memset(s, 0, sizeof(s));
		for (i = 0; i < n; i++) {
			scanf("%d %d %d", &v, &w, &l);
			E[i].v = v, E[i].w = w, E[i].l = l;
		}
		qsort(E, n, sizeof(edge), comp);
		for (i = j = ans = 0; j < m - 1; i++) {
			root1 = find(E[i].v, s), root2 = find(E[i].w, s);
			if (root1 != root2) {
				setunion(root1, root2, s);
				ans += E[i].l;
				j++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}