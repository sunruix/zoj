#include <stdio.h>
#include <string.h>

int G[1024][1024], known[1024], dist[1024];
int n, m;

void Dijkstra(int x)
{
	int v, w, maxdist;

	dist[x] = 0;
	while (1) {
		v = 1, maxdist = 0xfffffff;
		for (w = 2; w <= n; w++) {
			if (known[w] || dist[w] < 0)
				continue;
			if (dist[w] < maxdist) {
				v = w;
				maxdist = dist[w];
			}
		}
		if (v == n || v == 1)
			return;
		known[v] = 1;
		for (w = 2; w <= n; w++) {
			if (G[v][w] < 0 || known[w])
				continue;
			if (dist[w] < 0 || dist[w] > G[v][w] + dist[v])
				dist[w] = G[v][w] + dist[v];
		}
	}
}

int main()
{
	int t, k, i, j, d, v, w, x, max, ans, mom[32768];

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d %d", &n, &m);
		for (v = 1; v <= n; v++) {
			G[v][v] = 0;
			known[v] = 0;
			dist[v] = -1;
			for (w = 1; w <= n; w++)
				G[v][w] = -1;
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
			if (G[mom[j]][mom[j + 1]] < 0)
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
