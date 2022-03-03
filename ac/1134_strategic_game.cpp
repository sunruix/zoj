#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

int main()
{
	int n, i, j, k, v, w, d[1500], ans, m[1500];
	list<int> g[1500];

	while (scanf("%d", &n) != EOF) {
		memset(m, 0, sizeof(m)), memset(d, 0, sizeof(d));
		for (i = 0; i < n; i++) {
			scanf("%d:(%d)", &v, &j), d[v] += j;
			while (j--) {
				scanf("%d", &w), d[w]++;
				g[v].push_back(w), g[w].push_back(v);
			}
		}
		ans = 0, k = n;
		while (k > 1) {
			for (i = 0; i < n; i++) {
				if (d[i] == 1) {
					j = *(g[i].begin());
					if (!m[j])
						ans++, m[j] = 1;
					while (!g[j].empty()) {
						v = *g[j].begin();
						for (list<int>::iterator it = g[v].begin(); it != g[v].end(); it++)
							if (*it == j) {
								g[v].erase(it), d[v]--;
								break;
							}
						g[j].erase(g[j].begin()), k--, d[j]--;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}