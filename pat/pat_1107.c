#include <stdio.h>
#include <stdlib.h>

int n, g[2][1001][1001];
char visited[2][1001];

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int dfs(int u, int p) {
    int k, v, val = 0;
    if (visited[p][u])
        return 0;
    visited[p][u] = 1;
    for (k = 1; k <= g[p][u][0]; ++k)
        val += dfs(g[p][u][k], !p);
    return !p + val;
}

int main() {
    int i, j, k, u, v, ans[1001], pc;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d:", &g[0][i][0]);
        for (j = 1; j <= g[0][i][0]; ++j) {
            scanf("%d", &u);
            g[0][i][j] = u;
            k = ++g[1][u][0];
            g[1][u][k] = i;
        }
    }
    for (k = 0, i = 1; i <= n; ++i) {
        pc = dfs(i, 0);
        if (pc)
            ans[k++] = pc;
    }
    qsort(ans, k, sizeof(int), cmp);
    printf("%d\n", k);
    for (i = 0; i < k - 1; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
    return 0;
}

