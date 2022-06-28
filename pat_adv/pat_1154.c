#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int u, v;
} edge;

typedef struct {
    int begin, end;
} vector;

int cmp(const void *a, const void *b) {
    return ((edge *)a)->u - ((edge *)b)->u;
}

int cmpc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, m, i, j, k, u, v, w, coloring[10000], yes;
    edge E[20000] = {0};
    vector V[10000] = {0};
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    for (i = 0, m <<= 1; i < m; i += 2) {
        scanf("%d %d", &E[i].u, &E[i].v);
        E[i + 1].u = E[i].v;
        E[i + 1].v = E[i].u;
    }
    qsort(E, m, sizeof(edge), cmp);
    V[E[0].u].begin = 0;
    for (i = 1; i < m; ++i) {
        if (E[i].u != E[i - 1].u)
            V[E[i - 1].u].end = V[E[i].u].begin = i;
    }
    V[E[m - 1].u].end = m;
    scanf("%d", &k);
    while (k--) {
        yes = 1;
        for (i = 0; i < n; ++i)
            scanf("%d", &coloring[i]);
        for (u = 0; u < n && yes; ++u)
            for (i = V[u].begin; i < V[u].end && yes; ++i)
                yes = coloring[E[i].v] != coloring[u];
        if (!yes)
            printf("No\n");
        else {
            qsort(coloring, n, sizeof(int), cmpc);
            int count = 1, lastc = coloring[0];
            for (i = 1; i < n; ++i) {
                if (coloring[i] != lastc) {
                    lastc = coloring[i];
                    ++count;
                }
            }
            printf("%d-coloring\n", count);
        }
    }
    return 0;
}
