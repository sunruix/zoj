#include <stdio.h>
#include <string.h>

int main() {
    int nv, ne, i, j, k, m, u, v, g[1001][1001] = {0}, in[1001] = {0}, remove[1001], ans[10001], count = 0, yes;
    freopen("input", "r", stdin);
    scanf("%d %d", &nv, &ne);
    while (ne--) {
        scanf("%d %d", &u, &v);
        g[u][++g[u][0]] = v;
        ++in[v];
    }
    scanf("%d", &m);
    for (i = 0; i < m; ++i) {
        yes = 1;
        memset(remove, 0, sizeof(remove));
        for (j = 0; j < nv; ++j) {
            scanf("%d", &u);
            if (in[u] - remove[u] != 0)
                yes = 0;
            else {
                for (k = 1; k <= g[u][0]; ++k)
                    ++remove[g[u][k]];
            }
        }
        if (!yes)
            ans[count++] = i;
    }
    for (i = 0; i < count - 1; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
    return 0;
}
