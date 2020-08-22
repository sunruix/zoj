#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node {
	int type, day, i, j;
};

struct cmp {
	bool operator() (node *a, node *b) {
		if (a->day != b->day)
			return a->day > b->day;
		return a->type > b->type;
	}
};

node N[500][500], *temp;

int main()
{
	int m, n, query, ans[501 * 501], i, j, k, l;
	int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
	priority_queue <node *, vector <node *>, cmp> q;

	while (scanf("%d %d", &m, &n) != EOF) {
		memset(ans, 0, sizeof(ans));
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++) {
				N[i][j].i = i, N[i][j].j = j;
				scanf("%d", &k);
				if (k > 0) {
					N[i][j].day = 1, N[i][j].type = k;
					ans[k]++, q.push(&(N[i][j]));
				}
				else
					N[i][j].day = k, N[i][j].type = 0;
			}
		while (!q.empty()) {
			temp = q.top(), q.pop();
			l = -1024;
			for (k = 0; k < 4; k++) {
				i = temp->i + dir[k][0], j = temp->j + dir[k][1];
				if (i >= 0 && i < m && j >= 0 && j < n && !N[i][j].type) {
					if (N[i][j].day + temp->day >= 0) {
						N[i][j].type = temp->type, N[i][j].day = temp->day;
						ans[temp->type]++, q.push(&(N[i][j]));
					}
					else if (N[i][j].day > l)
						l = N[i][j].day;
				}
			}
			if (l != -1024)
				temp->day = -l, q.push(temp);
		}
		scanf("%d", &query);
		for (i = 0; i < query; i++)
			scanf("%d", &k), printf("%d\n", ans[k]);
	}
	return 0;
}