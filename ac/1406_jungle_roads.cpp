#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int v, w, l;
} edge;

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

int comp(const void *a, const void *b)
{
	return ((edge *)a)->l - ((edge *)b)->l;
}

int main()
{
	int n, i, j, k, l, e, ans, s[26], r1, r2;
	char cv, cw;
	edge E[13 * 25];

	while (scanf("%d\n", &n) != EOF && n) {
		memset(s, 0, sizeof(s));
		for (i = 0, e = 0; i < n - 1; i++) {
			scanf("%c %d ", &cv, &k);
			for (j = 0; j < k; j++) {
				scanf("%c %d ", &cw, &l);
				E[e].v = cv - 'A', E[e].w = cw - 'A', E[e++].l = l;
			}
		}
		qsort(E, e, sizeof(edge), comp);
		for (i = ans = l = 0; l < n - 1; i++)
			if ((r1 = find(E[i].v, s)) != (r2 = find(E[i].w, s))) {
				setunion(r1, r2, s);
				ans += E[i].l;
				l++;
			}
		printf("%d\n", ans);
	}
	return 0;
}