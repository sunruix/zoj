#include <stdio.h>
#include <string.h>

int main() {
    struct {
        int dst;
        unsigned char line;
    } g[10000][16] = {0};
    struct {
        int m, pre[5];
        unsigned char line[5], trans[5];
    } path[10000] = {0};
    int n, m, i, j, k, u, v, src, dst, q[10000], head, tail, dist[10000];
    unsigned char d[10000] = {0}, inq[10000];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &m);
        scanf("%d", &u);
        while (--m) {
            scanf("%d", &v);
            g[u][d[u]].dst = v;
            g[v][d[v]].dst = u;
            g[u][d[u]++].line = g[v][d[v]++].line = i;
            u = v;
        }
    }
    scanf("%d", &k);
    while (k--) {
        memset(inq, 0, sizeof(inq));
        scanf("%d %d", &src, &dst);
        head = tail = 0;
        q[tail++] = dst;
        inq[dst] = 1;
        path[dst].m = 1;
        path[dst].pre[0] = -1;
        path[dst].trans[0] = path[dst].line[0] = 0;
        dist[dst] = 0;
        while (src != (u = q[head++])) {
            inq[u] = 2;
            for (i = 0; i < d[u]; ++i) {
                v = g[u][i].dst;
                if (!inq[v]) {
                    inq[v] = 1;
                    q[tail++] = v;
                    dist[v] = dist[u] + 1;
                    path[v].m = 0;
                }
                if (inq[v] != 2 && dist[v] == dist[u] + 1) {
                    m = path[v].m;
                    path[v].pre[m] = u;
                    path[v].line[m] = g[u][i].line;
                    path[v].trans[m] = 0xff;
                    for (j = 0; j < path[u].m; ++j)
                        if (path[v].trans[m] > path[u].trans[j] + (path[v].line[m] != path[u].line[j]))
                            path[v].trans[m] = path[u].trans[j] + (path[v].line[m] != path[u].line[j]);
                    ++path[v].m;
                }
            }
        }
        printf("%d\n", dist[src]);
        int lasttrans = v = src, pi, pj;
        for (pi = i = 0; i < path[v].m; ++i)
            if (path[v].trans[pi] > path[v].trans[i])
                pi = i;
        while (v != dst) {
            u = path[v].pre[pi];
            for (pj = j = 0; j < path[u].m; ++j) {
                if (path[v].line[pi] == path[u].line[j])
                    pj = j;
                else if (path[u].trans[pj] > path[u].trans[j])
                    pj = j;
            }
            if (path[v].trans[pi] > path[u].trans[pj]) {
                printf("Take Line#%d from %04d to %04d.\n", path[v].line[pi], lasttrans, u);
                lasttrans = u;
            }
            v = u;
            pi = pj;
        }
    }
    return 0;
}
