#include <stdio.h>

int g[512][512], d[512], visited[512];

int dfs(int u) {
    int i, count;
    if (visited[u])
        return 0;
    count = visited[u] = 1;
    for (i = 1; i <= g[u][0]; ++i)
        count += dfs(g[u][i]);
    return count;
}

int main() {
    int n, m, i, u, v, yes = 0, odd = 0;
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &u, &v);
        ++d[u];
        ++d[v];
        g[u][++g[u][0]] = v;
        g[v][++g[v][0]] = u;
    }
    for (i = 1; i < n; ++i)
        printf("%d ", d[i]);
    printf("%d\n", d[i]);
    if (dfs(1) == n) {
        for (i = 1; i <= n; ++i)
            odd += d[i] & 1;
        if (odd == 0)
            yes = 2;
        else if (odd == 2)
            yes = 1;
    }
    printf("%s%s\n", yes ? (yes == 1 ? "Semi-" : "") : "Non-", "Eulerian");
    return 0;
}
