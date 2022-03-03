#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node {
	int i, j, ch, val;
};

struct cmp {
	bool operator() (node *a, node *b) {
		return a->ch > b->ch;
	}
};

int main()
{
	int n, k, i, j, s, t, ans;
	node G[128][128], *temp;
	priority_queue<node *, vector<node *>, cmp> q;

	while (scanf("%d %d", &n, &k) != EOF && n >= 0) {
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				G[i][j].i = i, G[i][j].j = j, G[i][j].val = 0;
				scanf("%d", &(G[i][j].ch));
				if (i || j)
					q.push(&(G[i][j]));
			}
		ans = G[0][0].val = G[0][0].ch;
		while (!q.empty()) {
			temp = q.top(), q.pop();
			j = temp->j;
			s = temp->i >= k ? temp->i - k : 0;
			t = temp->i + k < n ? temp->i + k : n - 1;
			for (i = s; i <= t; i++)
				if (G[i][j].ch < temp->ch && G[i][j].val)
					if (G[i][j].val + temp->ch > temp->val) {
						temp->val = G[i][j].val + temp->ch;
						if (ans < temp->val)
							ans = temp->val;
					}
			i = temp->i;
			s = temp->j >= k ? temp->j - k : 0;
			t = temp->j + k < n ? temp->j + k : n - 1;
			for (j = s; j <= t; j++)
				if (G[i][j].ch < temp->ch && G[i][j].val)
					if (G[i][j].val + temp->ch > temp->val) {
						temp->val = G[i][j].val + temp->ch;
						if (ans < temp->val)
							ans = temp->val;
					}
		}
		printf("%d\n", ans);
	}
	return 0;
}