#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

void dfs(int v, int n, int g[][32], int *vis)
{
	int w;

	for (vis[v] = 1, w = 0; w < n; w++)
		if (g[v][w] && !vis[w])
			dfs(w, n, g, vis);
}

int topsort(int start, int n, int g[][32], int *in, int *path)
{
	int i, inn[32], count;
	queue<int> q;

	memcpy(inn, in, 32 * sizeof(int));
	q.push(start), count = 0;
	while (!q.empty()) {
		q.pop(), count++;
		for (i = 0; i < n; i++)
			if (g[start][i])
				if (!(--inn[i])) {
					if (q.empty())
						q.push(i), path[start] = i;
					else
						return 0;
				}
		start = path[start];
	}
	return count;
}

int main()
{
	int n, m, i, j, k, rec[32], g[32][32], vis[32], in[32], path[32], con, incon, count, start;
	char c1, c2;

	while (scanf("%d %d\n", &n, &m) != EOF && n) {
		memset(g, 0, sizeof(g)), memset(in, 0, sizeof(in)), memset(rec, 0, sizeof(rec));
		for (i = con = incon = count = 0; i < m; i++) {
			scanf("%c<%c\n", &c1, &c2);
			if (!rec[c1 - 'A'])
				rec[c1 - 'A'] = 1, count++;
			if (!rec[c2 - 'A'])
				rec[c2 - 'A'] = 1, count++;
			g[c1 - 'A'][c2 - 'A'] = 1, in[c2 - 'A']++;
			if (!incon && !con) {
				memset(vis, 0, sizeof(vis));
				dfs(c2 - 'A', n, g, vis);
				if (vis[c1 - 'A']) {
					incon = i + 1;
					continue;
				}
				if (count == n) {
					for (j = 0; j < n && in[j]; j++);
					if (j < n && topsort(j, n, g, in, path) == n)
						con = i + 1, start = j;
				}
			}
		}
		if (con) {
			printf("Sorted sequence determined after %d relations: ", con);
			for (i = 0; i < n; i++, start = path[start])
				printf("%c", start + 'A');
			printf(".\n");
		}
		else if (incon)
			printf("Inconsistency found after %d relations.\n", incon);
		else
			printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}