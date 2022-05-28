#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int u, v;
} edge;

int cmp(const void *a, const void *b) {
    return ((edge *)a)->u - ((edge *)b)->u;
}

int main() {
    int n, m, k, i, u, v, p[10000][2] = {0}, visited[10000];
    edge E[20000];
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        E[i << 1].u = u;
        E[i << 1].v = v;
        E[(i << 1) + 1].u = v;
        E[(i << 1) + 1].v = u;
    }
    qsort(E, m << 1, sizeof(edge), cmp);
    memset(p, -1, sizeof(p));
    p[E[0].u][0] = 0;
    for (i = 1, m <<= 1; i < m; ++i) {
        if (E[i].u != E[i - 1].u) {
            p[E[i].u][0] = i;
            p[E[i - 1].u][1] = i - 1;
        }
    }
    p[E[i - 1].u][1] = i - 1;
    scanf("%d", &k);
    while (k--) {
        memset(visited, 0, sizeof(visited));
        int nv, ecount = 0;
        scanf("%d", &nv);
        while (nv--) {
            scanf("%d", &u);
            visited[u] = 1;
            for (i = p[u][0]; i >= 0 && i <= p[u][1]; ++i)
                ecount += !visited[E[i].v];
        }
        printf("%s\n", ecount == (m >> 1) ? "Yes" : "No");
    }
    return 0;
}
