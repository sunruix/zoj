#include <stdio.h>
#include <string.h>

#define INF 0xFFFFFFFF

unsigned n, m, g[1024][1024], dist[1024][1024], rec[1024];

void dijkstra(int src) {
    unsigned nxt, u, min, known[1024] = {0};

    while (1) {
        min = INF;
        for (u = 1; u <= n; ++u)
            if (u != src && !known[u] && min > dist[src][u])
                min = dist[src][nxt = u];
        if (min == INF)
            break;
        known[nxt] = 1;
        for (u = 1; u <= n; ++u)
            if (g[nxt][u] != INF && dist[src][u] > min + g[nxt][u])
                dist[src][u] = min + g[nxt][u];
    }
    rec[src] = 1;
}

int main() {
    unsigned int i, j, k, u, v, d, yes, src;
    freopen("input", "r", stdin);
    memset(dist, INF, sizeof(dist));
    memset(g, INF, sizeof(g));
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &d);
        g[u][v] = g[v][u] = d;
        dist[u][v] = dist[v][u] = d;
    }
    for (i = 1; i <= n; ++i)
        g[i][i] = dist[i][i] = 0;
    scanf("%d", &k);
    while (k--) {
        yes = 1;
        d = 0;
        scanf("%d", &src);
        if (!rec[src])
            dijkstra(src);
        for (i = 1; i < n; ++i) {
            scanf("%d", &u);
            if (dist[src][u] < d)
                yes = 0;
            d = dist[src][u];
        }
        printf("%s\n", yes ? "Yes" : "No");
    }
    return 0;
}
