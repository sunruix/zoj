#include <stdio.h>

int N, M, C1, C2, team[512], G[512][512];
int dist[512], known[512], call_team[512];
int diff_path[512];

void dijkstra()
{
	int v, w, i, j, temp;

	dist[C1] = 0;
	diff_path[C1] = 1;
	while (1) {
		v = -1;
		temp = 0x7fffffff;
		for (i = 0; i < N; i++) {
			if (known[i])
				continue;
			if (dist[i] >= 0 && dist[i] < temp) {
				temp = dist[i];
				v = i;
			}
		}
		if (v == C2)
			return;
		known[v] = 1;
		for (w = 0; w < N; w++) {
			if (G[v][w] == 0 || known[w])
				continue;
			if (dist[w] > 0 && dist[w] < dist[v] + G[v][w])
				continue;
			if (dist[w] < 0 || dist[w] > dist[v] + G[v][w]) {
				dist[w] = dist[v] + G[v][w];
				diff_path[w] = diff_path[v];
				call_team[w] = call_team[v] + team[w];
			}
			else {
				diff_path[w] += diff_path[v];
				if (call_team[w] < call_team[v] + team[w])
					call_team[w] = call_team[v] + team[w];
			}
		}
	}
}

int main()
{
	int i, j, v, w;

	scanf("%d %d %d %d", &N, &M, &C1, &C2);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			G[i][j] = 0;
		scanf("%d", &team[i]);
		call_team[i] = team[i];
		dist[i] = -1;
		known[i] = diff_path[i] = 0;
	}
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &v, &w, &j);
		G[v][w] = G[w][v] = j;
	}
	dijkstra();
	printf("%d %d\n", diff_path[C2], call_team[C2]);
	return 0;
}
