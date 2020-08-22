#include <stdio.h>

int find(int x, int s[])
{
	if (s[x] < 0)
		return x;
	else
		return (s[x] = find(s[x], s));
}

void setunion(int root1, int root2, int s[])
{
	if (root1 == root2)
		return;
	if (root1 * root2 == 0) {
		if (!root1)
			s[root2] = root1;
		else
			s[root1] = root2;
	}
	if (root1 < root2)
		s[root2] = root1;
	else {
		if (root1 == root2)
			s[root2]--;
		s[root1] = root2;
	}
}

int main()
{
	int m, n, root1, root2, i, j, k, s[30001], cur, pre, count;

	while (scanf("%d %d", &n, &m) != EOF && (m || n)) {
		for (i = 0; i < n; i++)
			s[i] = i;
		s[0] = -1;
		for (i = 0; i < m; i++) {
			scanf("%d", &k);
			for (j = 0; j < k; j++) {
				scanf("%d", &cur);
				if (s[cur] == cur)
					s[cur] = -1;
				if (j > 0)
					setunion(find(cur, s), find(pre, s), s);
				pre = cur;
			}
		}
		for (i = 0, count = 0; i < n; i++) {
			if (s[i] == i)
				continue;
			if (find(i, s) == 0)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
