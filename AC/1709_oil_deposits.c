#include <stdio.h>
#include <string.h>

int find(int x, int s[])
{
	if (s[x] <= 0)
		return x;
	return s[x] = find(s[x], s);
}

void setunion(int root1, int root2, int s[])
{
	if (root1 == root2)
		return;
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
	int n, m, i, j, k, s[32768], ans;
	char g[128][128];

	while (scanf("%d %d\n", &n, &m) != EOF && n) {
		memset(s, 0, sizeof(s));
		memset(g, 0, sizeof(g));
		for (i = 1, k = 0; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				scanf("%c", &g[i][j]), k++;
				if (g[i][j] == '@') {
					if (i > 1 && g[i - 1][j] == '@')
						setunion(find(k, s), find(k - m, s), s);
					if (j > 1 && g[i][j - 1] == '@')
						setunion(find(k, s), find(k - 1, s), s);
					if (i > 1 && j > 1 && g[i - 1][j - 1] == '@')
						setunion(find(k, s), find(k - m - 1, s), s);
					if (i > 1 && j < m && g[i - 1][j + 1] == '@')
						setunion(find(k, s), find(k - m + 1, s), s);
				}
			}
			getchar();
		}
		for (i = 1, ans = 0; i <= n; i++)
			for (j = 1; j <= m; j++)
				if (g[i][j] == '@' && s[(i - 1) * m + j] <= 0)
					ans++;
		printf("%d\n", ans);
	}
	return 0;
}