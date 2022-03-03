#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, m, i, j, ans[1024], vis[1024];
	vector<int> g[1024];
	queue<int> q;

	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 0; i < n; i++)
			g[i].clear(), vis[i] = ans[i] = 0;
		while (m--)
			scanf("%d %d", &i, &j), g[i].push_back(j), g[j].push_back(i);
		q.push(0);
		while (!q.empty()) {
			i = q.front(), q.pop(), vis[i] = 1;
			for (vector<int> :: iterator it = g[i].begin(); it != g[i].end(); it++)
				if (!vis[*it])
					q.push(*it);
		}
		memset(vis, 0, sizeof(vis));
		q.push(i);
		while (!q.empty()) {
			i = q.front(), q.pop(), vis[i] = 1;
			for (vector<int> :: iterator it = g[i].begin(); it != g[i].end(); it++)
				if (!vis[*it])
					ans[*it] = ans[i] + 1, q.push(*it);
		}
		ans[i] + 1 > 7 ? printf("%d\n", ans[i] + 1) : printf("Impossible\n");
	}
	return 0;
}