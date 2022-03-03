#include <cstdio>
#include <queue>

using namespace std;

struct node {
	char c;
	int i, j, step;
};

int main()
{
	int n, m, i, j, k, ans, dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
	node g[201][201], *temp;
	queue<node *> Q;

	while (scanf("%d %d\n", &n, &m) != EOF) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%c", &g[i][j].c), g[i][j].i = i, g[i][j].j = j, g[i][j].step = 0;
				if (g[i][j].c == 'r')
					Q.push(&g[i][j]);
			}
			getchar();
		}
		ans = 0x7fffffff;
		while (!Q.empty()) {
			temp = Q.front(), Q.pop();
			for (k = 0; k < 4; k++) {
				i = temp->i + dir[k][0], j = temp->j + dir[k][1];
				if (i >= 0 && i < n && j >= 0 && j < m) {
					if (g[i][j].c == 'a') {
						if (ans > temp->step + 1)
							ans = temp->step + 1;
						break;
					}
					if (g[i][j].c == '.' && (!g[i][j].step || g[i][j].step > temp->step + 1))
						g[i][j].step = temp->step + 1, Q.push(&g[i][j]);
					else if (g[i][j].c == 'x' && (!g[i][j].step || g[i][j].step > temp->step + 2))
						g[i][j].step = temp->step + 2, Q.push(&g[i][j]);
				}
			}
		}
		if (ans < 0x7fffffff)
			printf("%d\n", ans);
		else
			printf("Poor ANGEL has to stay in the prison all his life.\n");
	}
	return 0;
}