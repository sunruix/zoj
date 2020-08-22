#include <stdio.h>

int s[100011];
int find (int x)
{
	if (s[x] < 0)
		return x;
	return s[x] = find(s[x]);
}

void setunion(int root1, int root2)
{
	if (root1 == root2)
		return;
	if (s[root1] < s[root2]) {
		s[root1] += s[root2];
		s[root2] = root1;
	}
	else {
		s[root2] += s[root1];
		s[root1] = root2;
	}
}

int main()
{
	int n, m, i, v, w, root1, root2, ca = 1;
	char c;

	while (scanf("%d %d\n", &n, &m) != EOF) {
		for (i = 0; i <= n; i++)
			s[i] = -1;
		if (ca > 1)
			printf("\n");
		printf("Case %d:\n", ca++);
		while (m--) {
			scanf("%c", &c);
			if (c == 'M') {
				scanf("%d %d\n", &v, &w);
				root1 = find(v), root2 = find(w);
				setunion(root1, root2);
			}
			else {
				scanf("%d\n", &v);
				printf("%d\n", -1 * s[find(v)]);
			}
		}
	}
	return 0;
}
