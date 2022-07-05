/*
 * pat top level practice 1003 Universal Travel Sites
 */

#include <stdio.h>
#include <string.h>

#define INF 0x7FFFFFFF
#define IDX(c) ((c) - 'A')

int names[26][26][26], g[1024][1024], vn = 1, en, visited[1024];

int dfs(int u, int t, int f) {
    if (u == t)
        return f;
    int v;
    visited[u] = 1;
    for (v = 1; v < vn; ++v) {
        if (!visited[v] && g[u][v] > 0) {
            int d = dfs(v, t, f < g[u][v] ? f : g[u][v]);
            if (d > 0) {
                g[u][v] -= d;
                g[v][u] += d;
                return d;
            }
        }
    }
    return 0;
}

int main() {
    int n, i, j, u, v, cap, f, flow = 0;
    char c0, c1, c2;
    freopen("input", "r", stdin);
    scanf("%c%c%c ", &c0, &c1, &c2);
    names[IDX(c0)][IDX(c1)][IDX(c2)] = vn++;
    scanf("%c%c%c %d\n", &c0, &c1, &c2, &en);
    names[IDX(c0)][IDX(c1)][IDX(c2)] = vn++;
    for (i = 0; i < en; ++i) {
        scanf("%c%c%c ", &c0, &c1, &c2);
        if (!names[IDX(c0)][IDX(c1)][IDX(c2)])
            names[IDX(c0)][IDX(c1)][IDX(c2)] = vn++;
        u = names[IDX(c0)][IDX(c1)][IDX(c2)];
        scanf("%c%c%c %d\n", &c0, &c1, &c2, &cap);
        if (!names[IDX(c0)][IDX(c1)][IDX(c2)])
            names[IDX(c0)][IDX(c1)][IDX(c2)] = vn++;
        v = names[IDX(c0)][IDX(c1)][IDX(c2)];
        g[u][v] = cap;
    }
    flow += (f = dfs(1, 2, INF));
    while (f) {
        memset(visited, 0, sizeof(visited));
        flow += (f = dfs(1, 2, INF));
    }
    printf("%d\n", flow);
    return 0;
}
