#include <stdio.h>

int main() {
    int n, m, i, j, k, u, v, sum, start, yes;
    char g[256][256];
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &m);
        yes = m == n + 1;
        scanf("%d", &u);
        start = sum = u;
        for (i = 1; i < m; ++i) {
            scanf("%d", &v);
            if (!yes)
                continue;
            if (!g[u][v])
                yes = 0;
            else {
                sum += v;
                u = v;
            }
        }
        yes = yes && sum == (n * (n + 1) >> 1) + start && v == start;
        printf("%s\n", yes ? "YES" : "NO");
    }
    return 0;
}

