#include <stdio.h>
#include <string.h>

int G[1024][1024], visited[1024];
int part;
int N, M, K, list[1024];

void dfs(int v)
{
	int w;
	visited[v] = 1;
	for (w = 1; w <= N; w++)
		if (!visited[w] && G[v][w] == 1)
			dfs(w);
}

int check(int v)
{
	int w;
	part = 0;
	memset(visited, 0, sizeof(visited));
	for (w = 1; w <= N; w++) {
		if (G[v][w] == 1)
			G[v][w] = G[w][v] = -1;
	}
	for (w = 1; w <= N; w++) {
		if (w == v)
			continue;
		if (!visited[w]) {
			part++;
			dfs(w);
		}
	}
	for (w = 1; w <= N; w++) {
		if (G[v][w] == -1)
			G[v][w] = G[w][v] = 1;
	}
	return part - 1;
}

int main()
{
	int i, j, k, v, w;

	memset(G, 0, sizeof(G));
	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &v, &w);
		G[v][w] = G[w][v] = 1;
	}
	for (i = 0; i < K; i++)
		scanf("%d", &list[i]);
	for (i = 0; i < K; i++)
		printf("%d\n", check(list[i]));

	return 0;
}
