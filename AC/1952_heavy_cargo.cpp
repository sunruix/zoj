#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

/**
int main()
{
	int n, m, i, j, lim, path[201][201], G[201][201], visited[201];
	string v, w, start, end;
	map<string, int> M;
	queue<int> Q;
	freopen("input.txt", "r", stdin);
	while (cin >> n >> m && (n || m)) {
		M.clear();
		memset(G, 0, sizeof(G));
		memset(visited, 0, sizeof(visited));
		memset(path, 0, sizeof(path));
		for (i = j = 1; i <= m; i++) {
			cin >> v >> w >> lim;
			if (!M[v])
				M[v] = j++;
			if (!M[w])
				M[w] = j++;
			G[M[v]][M[w]] = G[M[w][M[v]] = lim;
		}
		cin >> start >> end;
		Q.push(M[start]);
		while (!Q.empty) {
			i = Q.front(), Q.pop(), visited[i] = 1;
			for (j = 1; j <= n; j++)
				if (G[i][j] && !visited[j])
					Q.push(j);
	}
	return 0;
}
**/