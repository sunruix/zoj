#include <stdio.h>
#include <string.h>

int n, g[1024][1024], dist[1024], known[1024];

void Dijkstra(int source, int target)
{
	int v, w, i, len;

	while (!known[target]) {
		for (v = 0, len = 0x7fffffff, i = 1; i < n; i++)
			if (!known[i])
				if (dist[i] && dist[i] < len)
					len = dist[i], v = i;
		if (known[0] && v == 0)
			break;
		for (known[v] = 1, w = 1; w < n; w++)
			if (!known[w] && g[v][w])
				if (!dist[w] || dist[v] + g[v][w] < dist[w])
					dist[w] = dist[v] + g[v][w];
	}
}

int main()
{
	int i, j, t[1024];
	char s[1024][512];

	while (scanf("%d", &n) != EOF && n) {
		if (n == 1) {
			printf("0\n");
			continue;
		}
		memset(g, 0, sizeof(g)), memset(known, 0, sizeof(known)), memset(dist, 0, sizeof(known));
		for (i = 0; i < n; i++) {
			scanf("%d %s", &t[i], s[i]);
			for (j = 0; j < i; j++) {
				if (!strncmp(s[i], s[j] + strlen(s[j]) - 4, 4))
					g[j][i] = t[j];
				if (!strncmp(s[j], s[i] + strlen(s[i]) - 4, 4))
					g[i][j] = t[i];
			}
		}
		Dijkstra(0, n - 1);
		printf("%d\n", dist[n - 1] ? dist[n - 1] : -1);
	}
	return 0;
}