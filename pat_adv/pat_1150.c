#include <stdio.h>
#include <string.h>

int main() {
    int n, m, i, j, k, u, v, d, iq, g[256][256] = {0}, visited[256], shortest = 0x7FFFFFFF;
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d", &u, &v, &d);
        g[u][v] = g[v][u] = d;
    }
    scanf("%d", &m);
    for (iq = 1; iq <= m; ++iq) {
        scanf("%d", &k);
        memset(visited, 0, sizeof(visited));
        int dist = 0, na = 0, vc = 0, head;
        scanf("%d", &u);
        head = u;
        vc = visited[u] = 1;
        for (i = 1; i < k; ++i) {
            scanf("%d", &v);
            if (!g[u][v])
                na = 1;
            else
                dist += g[u][v];
            if (!visited[v])
                vc += (visited[v] = 1);
            u = v;
        }
        if (na)
            printf("Path %d: NA (Not a TS cycle)\n", iq);
        else {
            printf("Path %d: %d (%s)\n", iq, dist, (vc == n && head == v) ? (k == n + 1 ? "TS simple cycle" : "TS cycle") : "Not a TS cycle");
            if (vc == n && head == v && shortest > dist) {
                shortest = dist;
                j = iq;
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", j, shortest);
    return 0;
}
