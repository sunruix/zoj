#include <stdio.h>
#include <string.h>
#define chk(x, y) (g[x][y] == '.' || g[x][y] == '@')

int find(int x, int s[])
{
	if (s[x] < 0)
		return x;
	return s[x] = find(s[x], s);
}

void setunion(int root1, int root2, int s[])
{
	if (root1 == root2)
		return;
	s[root1] += s[root2];
	s[root2] = root1;
}

int main()
{
	int n, m, i, j, k, a, s[32 * 32];
	char g[32][32];

	while (scanf("%d %d\n", &m, &n) != EOF && n) {
		memset(s, -1, sizeof(s));
		for (i = k = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				scanf("%c", &g[i][j]);
				if (g[i][j] == '@')
					a = k;
				if (chk(i, j)) {
					if (i > 1 && chk(i - 1, j))
						setunion(k, find(k - m, s), s);
					if (j > 1 && chk(i, j - 1))
						setunion(k, find(k - 1, s), s);
				}
				k++;
			}
			getchar();
		}
		printf("%d\n", -1 * s[find(a, s)]);
	}
	return 0;
}