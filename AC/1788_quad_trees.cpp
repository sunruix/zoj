#include <cstdio>
#include <cstring>
#include <queue>

typedef struct {
	int i, j, k;
} node;

char g[512][512], s[1024 * 1024], ans[1024 * 1024];

int check(node x)
{
	int ii, jj, ans = 0;

	for (ii = x.i; ii < x.i + x.k; ii++)
		for (jj = x.j; jj < x.j + x.k; jj++)
			ans += g[ii][jj];
	return ans;
}

int main()
{
	int n, i, j, k, t;
	node a, b;
	std::queue<node> q;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &g[i][j]);
		i = 0, memset(s, 0, sizeof(s));
		memset(ans, 0, sizeof(ans));
		a.i = 0, a.j = 0, a.k = n;
		q.push(a);
		while (!q.empty()) {
			b = q.front(), q.pop();
			if (b.k > 1) {
				k = check(b);
				if (k == 0)
					s[i++] = 0, s[i++] = 0;
				else if (k == b.k * b.k)
					s[i++] = 0, s[i++] = 1;
				else {
					s[i++] = 1;
					a.k = b.k >> 1;
					a.i = b.i, a.j = b.j, q.push(a);
					a.j = b.j + (b.k >> 1), q.push(a);
					a.i = b.i + (b.k >> 1), a.j = b.j, q.push(a);
					a.i = b.i + (b.k >> 1), a.j = b.j + (b.k >> 1), q.push(a);
				}
			}
			else
				s[i++] = 0, s[i++] = g[b.i][b.j];
		}
		for (j = 0, i--; i - 3 >= 0; i -= 4)
			ans[j++] = s[i] + (s[i - 1] << 1) + (s[i - 2] << 2) + (s[i - 3] << 3);
		ans[j] = (i >= 0 ? s[i] : 0) + (i >= 1 ? (s[i - 1] << 1) : 0) + (i >= 2 ? (s[i - 2] << 2) : 0);
		for (; j >= 0; j--)
			printf("%X", ans[j]);
		printf("\n");
	}
	return 0;
}