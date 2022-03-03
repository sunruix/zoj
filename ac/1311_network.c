#include <stdio.h>
#include <string.h>

int n, g[128][128], vis[128], low[128], parent[128], rc, vic, ans;

void find_art(int v, int root)
{
	int w, flag = 0;

	vis[v] = low[v] = ++vic;
	for (w = 1; w <= n; w++) {
		if (g[v][w]) {
			if (!vis[w]) {
				v == root ? rc++ : 0;
				parent[w] = v;
				find_art(w, root);
				if (vis[v] <= low[w] && v != root)
					!flag ? flag = 1, ans++ : 0;
				low[w] < low[v] ? low[v] = low[w] : 0;
			}
			else if (parent[v] != w)
				vis[w] < low[v] ? low[v] = vis[w] : 0;
		}
	}
}

int main()
{
	int i, j, a[1024];
	char s[1024], t[1024];

	while (scanf("%d\n", &n) != EOF && n) {
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));
		while (fgets(s, 1024, stdin) && strcmp(s, "0\n")) {
			i = j = 0;
			while (sscanf(s + j, "%s", t) != EOF)
				sscanf(t, "%d", &a[i++]), j += strlen(t) + 1;
			for (j = 1; j < i; j++)
				g[a[0]][a[j]] = g[a[j]][a[0]] = 1;
		}
		ans = vic = rc = 0;
		find_art(1, 1);
		printf("%d\n", rc > 1 ? ans + 1 : ans);
	}
	return 0;
}
