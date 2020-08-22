#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct edge {
	int id, len;

	edge() {}
	edge(int i, int l) {
		id = i, len = l;
	}
};

struct node {
	int id, min;

	node () {}
	node (int i, int m) {
		id = i, min = m;
	}

	friend bool operator <(node a, node b) {
		return a.min < b.min;
	}
};

int vis[100001], ans[100001];
vector<edge> g[100001];

int Dijkstra(int src, int dst)
{
	int dis;
	node temp;
	priority_queue<node> q;

	memset(vis, 0, sizeof(vis)), memset(ans, 0, sizeof(ans));
	ans[src] = 0x7fffffff, q.push(node(src, 0x7fffffff));
	while (!q.empty()) {
		temp = q.top(), q.pop(), vis[temp.id] = 1;
		if (temp.id == dst)
			break;
		for (vector<edge> :: iterator it = g[temp.id].begin(); it != g[temp.id].end(); it++)
			if (!vis[it->id]) {
				dis = temp.min < it->len ? temp.min : it->len;
				if (ans[it->id] < dis)
					ans[it->id] = dis, q.push(node(it->id, dis));
			}
	}
	while (!q.empty())
		q.pop();
	return ans[dst];
}

int main()
{
	int n, m, i, j, k;
	edge temp;

	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 1; i <= n; i++)
			g[i].clear();
		while (m--) {
			scanf("%d %d %d", &i, &j, &k);
			g[i].push_back(edge(j, k)), g[j].push_back(edge(i, k));
		}
		scanf("%d %d", &i, &j);
		printf("%d\n", Dijkstra(i, j));
	}
	return 0;
}
