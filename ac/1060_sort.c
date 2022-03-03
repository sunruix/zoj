#include <stdio.h>
#include <string.h>

int n, m, G[32][32], visited[32], vc[32], fc[32], path[32], count, error;

void dfs(int v)
{
	int w;
	if (error || count == n)
		return;
	visited[v] = 1;
	vc[v] = count, fc[v] = 0;
	path[count++] = v;
	for (w = 0; w < n; w++) {
		if (G[v][w]) {
			if (visited[w] && !fc[w])
				error = 1;
			else if (!visited[w])
				dfs(w);
		}
	}
	fc[v] = 1;
}

int main()
{
	int v, w, i, j, k, yp, np, out[32], in[32], ic, oc;
	char c1, c2, s[32];
	freopen("input", "r", stdin);
	while (scanf("%d %d\n", &n, &m) != EOF && (n || m)) {
		error = yp = np = 0;
		memset(G, 0, sizeof(G)); memset(out, 0, sizeof(out)); memset(in, 0, sizeof(in));
		for (i = 0; i < m; i++) {
			scanf("%c<%c\n", &c1, &c2);
			if (yp || np)
				continue;
			G[c1 - 'A'][c2 - 'A'] =  out[c1 - 'A'] = in[c2 - 'A'] = 1;
			if (c1 == c2) {
				error = 1;
				np = i + 1;
			}
			for (j = 0, ic = oc = 0; j < n; j++) {
				if (in[j] == 0 && out[j] != 0)
					ic++;
				else if (in[j] != 0 && out[j] == 0)
					oc++;
			}
			for (v = 0; v < n && !error; v++) {
				if (out[v] != 0) {
					memset(visited, 0, sizeof(visited));
					count = 0;
					dfs(v);
					if (error && !np)
						np = i + 1;
					else if (count == n && !yp && ic <= 1 && oc <= 1) {
						yp = i + 1;
						for (j = 0; j < n; j++)
							s[j] = 'A' + path[j];
						s[j] = '\0';
					}
				}
			}
		}
		if (error)
			printf("Inconsistency found after %d relations.\n", np);
		else if (!yp && !np)
			printf("Sorted sequence cannot be determined.\n");
		else
			printf("Sorted sequence determined after %d relations: %s.\n", yp, s);
	}
	return 0;
}
