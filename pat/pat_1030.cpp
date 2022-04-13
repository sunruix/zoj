#include <stdio.h>
#include <string.h>

int n, m;
int G[505][505], dist[505], cost[505][505];
int visited[505], next[505], c[505];

void Dijkstra(int start, int end)
{
	int v, w, min;
	next[end] = -1, dist[end] = 0;
	while (1) {
		for (w = 0, min = 0x7fffffff; w < n; w++)
			if (!visited[w] && dist[w] >= 0 && dist[w] < min)
				min = dist[w], v = w;
		visited[v] = 1;
		if (v == start)
			return ;
		for (w = 0; w < n; w++) {
			if (visited[w] || !G[v][w])
				continue;
			if (dist[w] < 0 || dist[v] + G[v][w] < dist[w]) {
				dist[w] = dist[v] + G[v][w];
				c[w] = c[v] + cost[v][w];
				next[w] = v;
			}
			else if (dist[v] + G[v][w] == dist[w] &&
				c[v] + cost[v][w] < c[w])
				c[w] = c[v] + cost[v][w], next[w] = v;
		}
	}
}


int main()
{
	int i, j, k, v, w, start, end;

	scanf("%d %d %d %d", &n, &m, &start, &end);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d %d", &v, &w, &j, &k);
		G[v][w] = G[w][v] = j, cost[v][w] = cost[w][v] = k;
	}
	memset(dist, -1, sizeof(dist));
	Dijkstra(start, end);
	for (i = start; i != end; i = next[i])
		printf("%d ", i);
	printf("%d %d %d\n", end, dist[start], c[start]);
	return 0;
}