#include <stdio.h>
#include <string.h>

char g[1024][1024], vis[1024];
int n, ans[1024], parent[1024], low[1024], visc, maxp, conn;

void find_art(int v)
{
	int w;

	vis[v] = 1, low[v] = vis[v] = ++visc;
	for (w = 1; w <= maxp; w++) {
		if (g[v][w]) {
			if (!vis[w]) {
				parent[w] = v;
				find_art(w);
				if (vis[v] <= low[w])
					ans[v]++, conn++;
				low[v] = low[v] < low[w] ? low[v] : low[w];
			}
			else if (parent[v] != w)
				low[v] = low[v] < vis[w] ? low[v] : vis[w];
		}
	}
}

int main()
{
	int i, j, v, w, count = 0;

	while (1) {
		scanf("%d", &v);
		if (v) {
			scanf("%d", &w);
			g[v][w] = g[w][v] = 1;
			maxp = v > maxp ? v : maxp;
			maxp = w > maxp ? w : maxp;
		}
		else {
			if (!maxp)
				break;
			visc = 0;
			find_art(maxp);
			ans[maxp] = ans[maxp] > 1 ? ans[maxp] - 1 : 0;
			if (count++)
				printf("\n");
			printf("Network #%d\n", count);
			if (conn <= 1)
				printf("  No SPF nodes\n");
			else {
				for (i = j = 1; i <= maxp; i++)
					if (ans[i])
						printf("  SPF node %d leaves %d subnets\n", i, ans[i] + 1);
			}
			memset(g, 0, sizeof(g)), memset(vis, 0, sizeof(vis));
			memset(ans, 0, sizeof(ans)), memset(parent, 0, sizeof(low));
			conn = maxp = 0;
		}
	}
	return 0;
}