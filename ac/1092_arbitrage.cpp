#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int t = 1, n, m, i, j, k, ans;
	double g[32][32], exch;
	string s1, s2;
	map<string, int> M;

	while (cin >> n && n) {
		memset(g, 0, sizeof(g));
		for (i = 1; i <= n; i++)
			cin >> s1, M[s1] = i;
		cin >> m;
		for (k = 0; k < m; k++) {
			cin >> s1 >> exch >> s2;
			i = M[s1], j = M[s2], g[i][j] = exch;
		}
		for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					g[i][j] = max(g[i][j], g[i][k] * g[k][j]);
		for (ans = 0, i = 1; i <= n && !ans; i++)
			ans = g[i][i] > 1 + 1e-4;
		printf("Case %d: %s", t++, ans ? "Yes\n" : "No\n");
	}
	return 0;
}