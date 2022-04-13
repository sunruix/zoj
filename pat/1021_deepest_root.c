#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int *adjlist;
	int adjnum;
} node;

int N, visited[10001], d[10001], dpst[10001];
node n[10001];

int dfs(int v)
{
	int w, max = 0, m;
	visited[v] = 1;
	for (w = 0; w < n[v].adjnum; w++) {
		if (visited[n[v].adjlist[w]])
			continue;
		m = 1 + dfs(n[v].adjlist[w]);
		if (m > max)
		max = m;
	}
	return max;
}

int main()
{
	int i, j, k, v, w;
	int max = 0, count = 0, e[10001][2];

	scanf("%d", &N);
	for (i = 0; i < N - 1; i++) {
		scanf("%d %d", &v, &w);
		e[i][0] = v, e[i][1] = w;
		d[v]++, d[w]++;
	}
	for (i = 0; i < N - 1; i++) {
		v = e[i][0], w = e[i][1];
		if (n[v].adjlist == NULL)
			n[v].adjlist = malloc(d[v] * sizeof(int));
		if (n[w].adjlist == NULL)
			n[w].adjlist = malloc(d[w] * sizeof(int));
		n[v].adjlist[n[v].adjnum++] = w;
		n[w].adjlist[n[w].adjnum++] = v;
	}
	for (i = 1; i <= N; i++)
		if (!visited[i]) {
			count++;
			dfs(i);
		}
	if (count > 1) {
		printf("Error: %d components\n", count);
		return 0;
	}
	for (i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		dpst[i] = dfs(i);
		if (max < dpst[i])
			max = dpst[i];
	}
	for (i = 1; i <= N; i++)
		if (dpst[i] == max)
			printf("%d\n", i);
	return 0;
}
