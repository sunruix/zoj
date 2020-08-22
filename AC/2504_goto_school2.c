#include <stdio.h>
#include <string.h>

const int MAX = 0xfffffff;
int G[1024][1024], known[1024], dist[1024];
int n, m;

void Dijkstra(int x)
{
	int v, w, maxdist;

	dist[x] = 0;
	while (1) {
		v = 1, maxdist = MAX;
		for (w = 2; w <= n; w++) {
			if (!known[w] && dist[w] < maxdist) {
				v = w;
				maxdist = dist[w];
			}
		}
		if (v == n || v == 1)
			return;
		known[v] = 1;
		for (w = 2; w <= n; w++) {
			if (dist[w] > G[v][w] + dist[v])
				dist[w] = G[v][w] + dist[v];
		}
	}
}

int main()
{
	int t, k, i, j, d, v, w, x, max, ans, mom[32768];
	freopen("input", "r", stdin);
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d %d", &n, &m);
		memset(mom, 0, sizeof(mom));
		for (v = 1; v <= n; v++) {
			dist[v] = MAX;
			known[v] = 0;
			G[v][v] = 0;
			for (w = 1; w <= n; w++)
				G[v][w] = MAX;
		}
		x = max = 0, ans = 1;
		while (m--) {
			scanf("%d %d %d", &v, &w, &d);
			G[v][w] = G[w][v] = d;
		}
		scanf("%d", &k);
		for (j = 1; j <= k; j++) {
			scanf("%d", &mom[j]);
		}
		for (j = 2; j <= k - 1 && ans; j++) {
			if (G[mom[j]][mom[j + 1]] == MAX)
				ans = 0;
			else
				max += G[mom[j]][mom[j + 1]];
		}
		if (!ans) {
			printf("TEST %d N\n", i);
			continue;
		}
		x = mom[2];
		Dijkstra(x);
		ans = max - dist[n];
		printf("TEST %d Y %d\n", i, ans);
	}
	return 0;
}
