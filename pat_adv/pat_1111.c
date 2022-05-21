#include <stdio.h>
#include <string.h>

#define INF 0xFFFFFFFF

unsigned n, m, src, dst, G[500][500][2], dist[500], lpath[500], tpath[500];

void dijkstra(int lt, unsigned *pre) {
    unsigned i, u, v, min, known[500] = {0}, assis[500];
    memset(dist, INF, sizeof(dist));
    memset(assis, INF, sizeof(assis));
    assis[src] = dist[src] = 0;
    pre[src] = n;
    while (1) {
        min = INF;
        for (u = n, i = 0; i < n; ++i)
            if (!known[i] && dist[i] < min)
                min = dist[u = i];
        if (u == n)
            break;
        known[u] = 1;
        for (v = 0; v < n; ++v) {
            if (u == v || G[u][v][lt] == INF)
                continue;
            if (G[u][v][lt] + dist[u] < dist[v]) {
                dist[v] = G[u][v][lt] + dist[u];
                assis[v] = assis[u] + (lt ? 1 : G[u][v][1]);
                pre[v] = u;
            }
            else if (G[u][v][lt] + dist[u] == dist[v] && assis[v] > assis[u] + (lt ? 1 : G[u][v][1])) {
                assis[v] = assis[u] + (lt ? 1 : G[u][v][1]);
                pre[v] = u;
            }
        }
    }
}

void pathstr(unsigned *path, char *s) {
    int u, v, w;
    for (v = dst, w = n; v != n; v = u) {
        u = path[v];
        path[v] = w;
        w = v;
    }
    for (v = src; path[v] != n; v = path[v])
        sprintf(s + strlen(s), "%d -> ", v);
    sprintf(s + strlen(s), "%d", v);
}

int main() {
    int i, u, v, w, l, t, ldist, tdist, same = 1;
    char ls[4096] = {0}, ts[4096] = {0};
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    memset(G, INF, sizeof(G));
    while (m--) {
        scanf("%d %d %d %d %d", &u, &v, &w, &l, &t);
        G[u][v][0] = l;
        G[u][v][1] = t;
        if (!w) {
            G[v][u][0] = l;
            G[v][u][1] = t;
        }
    }
    scanf("%d %d", &src, &dst);
    dijkstra(0, lpath);
    ldist = dist[dst];
    dijkstra(1, tpath);
    tdist = dist[dst];
    pathstr(lpath, ls);
    pathstr(tpath, ts);
    if (!strcmp(ls, ts))
        printf("Distance = %d; Time = %d: %s\n", ldist, tdist, ls);
    else
        printf("Distance = %d: %s\nTime = %d: %s\n", ldist, ls, tdist, ts);
    return 0;
}
