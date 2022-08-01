#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int i, j, c, id;
} edge;

int comp_edge(const void *a, const void *b)
{
    return ((edge *)a)->c - ((edge *)b)->c;
}

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void dfs(int i, int n, int g[][128], int *vis)
{
    int j;

    for (vis[i] = 1, j = 1; j <= n; j++)
        if (!vis[j] && g[i][j])
            dfs(j, n, g, vis);
}

int main()
{
    int t = 0, n, m, i, j, k, c, g[128][128], ans[512], vis[128];
    edge e[512];

    while (scanf("%d %d", &n, &m) != EOF) {
        memset(g, 0, sizeof(g));
        for (k = 0; k < m; k++) {
            scanf("%d %d %d", &i, &j, &c);
            g[i][j] = g[j][i] = 1;
            e[k].i = i, e[k].j = j, e[k].c = c, e[k].id = k + 1;
        }
        qsort(e, m, sizeof(edge), comp_edge);
        for (k = 0; k < m; k++) {
            i = e[k].i, j = e[k].j, g[i][j] = g[j][i] = 0, ans[k] = e[k].id;
            memset(vis, 0, sizeof(vis)), dfs(1, n, g, vis);
            if (!vis[n])
                break;
        }
        qsort(ans, ++k, sizeof(int), comp);
        if (t++)
            printf("\n");
        printf("%d\n", k);
        for (i = 0; i < k; i++)
            printf("%d%c", ans[i], i == k - 1 ? '\n' : ' ');
    }
    return 0;
}
