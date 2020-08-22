#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	int n, m, x, y, i, j, k, ans;
	const int dir[8][2] = {-1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1};
	char G[32][32], v[32][32];
	queue< pair<int, int> > Q;

	while (scanf("%d %d %d %d\n", &n, &m, &x, &y) != EOF && n) {
		memset(G, 0, sizeof(G)), memset(v, 0, sizeof(v)), ans = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++)
				scanf("%c", &G[i][j]);
			getchar();
		}
		v[x][y] = 1, Q.push(pair<int, int>(x, y));
		while (!Q.empty()) {
			x = Q.front().first, y = Q.front().second, Q.pop();
			for (k = 0; k < 8; k++) {
				i = dir[k][0] + x, j = dir[k][1] + y;
				if (i > 0 && i <= n && j > 0 && j <= m) {
					if (G[i][j] == 'X' && !v[i][j])
						Q.push(pair<int, int>(i, j)), v[i][j] = 1;
					else if (G[i][j] == '.' && k & 1)
						ans++;
				}
				else if (k & 1)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}