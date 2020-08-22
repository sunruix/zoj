#include <stdio.h>
#include <string.h>

int G[1024][1024], visited[1024], parent[1024];
int n, m, perfect;

void dfs(int v)
{
	int w, x;
	
	if (!perfect)
		return;
	visited[v] = 1;
	for (w = 1; w <= n; w++) {
		if (!G[v][w] || visited[w])
			continue;
		for (x = 1; x <= n; x++) {
			if (x == v || !G[w][x] || !visited[x])
				continue;
			if (!G[v][x]) {
				perfect = 0;
				return;
			}
		}
		parent[w] = v;
		dfs(w);
	}
}

int main()
{
	int i, j, v, w;
	freopen("input1", "r", stdin);

	while (scanf("%d %d", &n, &m) != EOF && n && m) {
		perfect = 1;
		memset(G, 0, sizeof(G));
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		for (i = 0; i < m; i++) {
			scanf("%d %d", &v, &w);
			G[v][w] = G[w][v] = 1;
		}
		if (n <= 3) {
			printf("Perfect\n\n");
			continue;
		}
		for (i = 1; i <= n && perfect; i++)
			if (!visited[i])
				dfs(i);
		if (perfect)
			printf("Perfect\n\n");
		else
			printf("Imperfect\n\n");
	}
	return 0;
}
