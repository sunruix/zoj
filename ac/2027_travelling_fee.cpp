#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main()
{
	int m, n, i, j, k, g[256][256], in[256], ans;
	string s1, s2;
	vector<int> dis[256];
	vector<int> lon[256];
	map<string, int> M;
	queue<int> q;

	while (cin >> s1 >> s2) {
		M[s1] = 1, M[s2] = 2;
		scanf("%d", &m), n = 3;
		memset(g, -1, sizeof(g)), memset(in, 0, sizeof(in));
		while (m--) {
			cin >> s1 >> s2 >> k;
			i = M[s1] ? M[s1] : (M[s1] = n++);
			j = M[s2] ? M[s2] : (M[s2] = n++);
			g[i][j] = k, in[j]++;
		}
		q.push(1), dis[1].push_back(0), lon[1].push_back(0);
		while (!q.empty()) {
			i = q.front(), q.pop();
			for (j = 2; j < n; j++)
				if (g[i][j] >= 0) {
					for (k = 0; k < dis[i].size(); k++)
						dis[j].push_back(dis[i][k] + g[i][j]), lon[j].push_back(lon[i][k] > g[i][j] ? lon[i][k] : g[i][j]);
					if (!(--in[j]))
						q.push(j);
				}
		}
		for (ans = 0x7fffffff, i = 0; i < dis[2].size(); i++)
			if (ans > dis[2][i] - lon[2][i])
				ans = dis[2][i] - lon[2][i];
		for (i = 1; i < n; i++)
			dis[i].clear(), lon[i].clear();
		M.clear();
		printf("%d\n", ans);
	}
	return 0;
}
