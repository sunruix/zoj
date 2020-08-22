#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef struct {
	int i, j, k, hp, t;
} node;

int main()
{
	int n, m, i, j, k, ans, dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
	node g[8][8], *temp;
	queue<node *> Q;

	while (scanf("%d %d", &n, &m) != EOF && n) {
		memset(g, 0, sizeof(g)), ans = 0;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++) {
				scanf("%d", &g[i][j].k), g[i][j].i = i, g[i][j].j = j;
				if (g[i][j].k == 2)
					g[i][j].hp = 6, Q.push(&g[i][j]);
			}
		while (!Q.empty() && !ans) {
			temp = Q.front(), Q.pop();
			for (k = 0; k < 4; k++) {
				i = temp->i + dir[k][0], j = temp->j + dir[k][1];
				if (i >= 0 && i < m && j >= 0 && j < n && g[i][j].k) {
					if (temp->hp > 1) {
						if (g[i][j].k == 3) {
							ans = temp->t + 1;
							break;
						}
						else if (g[i][j].k == 4 && !g[i][j].t)
							g[i][j].t = temp->t + 1, g[i][j].hp = 6, Q.push(&g[i][j]);
						else if (g[i][j].k == 1 && g[i][j].hp < temp->hp - 1)
							g[i][j].t = temp->t + 1, g[i][j].hp = temp->hp - 1, Q.push(&g[i][j]);
					}
				}
			}
		}
		printf("%d\n", ans ? ans : -1);
		while (!Q.empty())
			Q.pop();
	}
	return 0;
}