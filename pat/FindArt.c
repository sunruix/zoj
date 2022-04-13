#include <stdio.h>
#include <string.h>

int G[1024][1024], Num[1024], Low[1024];
int visited[1024], isart[1024], parent[1024];
int counter = 0;
int N, M, K, list[1024];

void findart(int v)
{
	int w;

	visited[v] = 1;
	Low[v] = Num[v] = counter++;
	for (w = 1; w <= N; w++) {
		if (!G[v][w])
			continue;
		if (!visited[w])
		{
			parent[w] = v;
			findart(w);
			if (Low[w] >= Num[v])
				isart[v] = 1;
			Low[v] = Low[v] < Low[w] ? Low[v] : Low[w];
		}
		else
			if (parent[v] != w)
				Low[v] = Low[v] < Num[w] ? Low[v] : Num[w];
	}
}

int main()
{
	int i, j, k, v, w;
	int edge;

	memset(G, 0, sizeof(G));
	memset(Num, 0, sizeof(Num));
	memset(parent, 0, sizeof(parent));
	memset(Low, 0, sizeof(Low));
	memset(visited, 0, sizeof(visited));
	memset(isart, 0, sizeof(isart));
	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &v, &w);
		G[v][w] = G[w][v] = 1;
	}
	for (i = 0; i < K; i++)
		scanf("%d", &list[i]);
	findart(1);
	for (i = 0; i < K; i++)
		printf("%d\n", isart[list[i]]);

	return 0;
}
