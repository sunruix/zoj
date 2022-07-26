#include <stdio.h>
#include <stdlib.h>

int n, m, s, g[128][128], w[128], buf[128], paths[128][128], *ans[128], acount;

int cmp(const void *a, const void *b) {
    int *pa = *(int **)a, *pb = *(int **)b;
    for (++pa, ++pb; *pa && *pb && *pa == *pb; ++pa, ++pb);
    return *pb - *pa;
}

void search(int id, int sum, int len) {
    int i;
    if (w[id] + sum == s && !g[id][0]) {
        paths[acount][len] = w[id];
        while (len--)
            paths[acount][len] = buf[len];
        ans[acount] = paths[acount];
        ++acount;
    }
    else if (w[id] + sum < s) {
        buf[len] = w[id];
        for (i = 1; i <= g[id][0]; ++i)
            search(g[id][i], w[id] + sum, len + 1);
    }
}

int main() {
    int u, v, i, j, k;
    freopen("input", "r", stdin);
    scanf("%d %d %d", &n, &m, &s);
    for (i = 0; i < n; ++i)
        scanf("%d", &w[i]);
    while (m--) {
        scanf("%d", &u);
        scanf("%d", &g[u][0]);
        for (i = 1; i <= g[u][0]; ++i)
            scanf("%d", &g[u][i]);
    }
    search(0, 0, 0);
    qsort(ans, acount, sizeof(int *), cmp);
    for (i = 0; i < acount; ++i) {
        for (j = 0; *(ans[i] + j + 1); ++j)
            printf("%d ", *(ans[i] + j));
        printf("%d\n", *(ans[i] + j));
    }
    return 0;
}
