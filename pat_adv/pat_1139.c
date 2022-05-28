#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, gender[10000], g[10000][2], visited[10000], path[4], count, ans[90000];
struct pair {
    int id1, id2;
} E[90000];

int cmp(const void *a, const void *b) {
    struct pair *pa = (struct pair *)a, *pb = (struct pair *)b;
    return pa->id1 != pb->id1 ? pa->id1 - pb->id1 : pa->id2 - pb->id2;
}

void search(int u, int targ, int l) {
    if (visited[u] || (u == targ && l != 3))
        return;
    if (l == 3) {
        if (u == targ)
            ans[count++] = path[1];
        return;
    }
    visited[u] = 1;
    int i, gend = l == 0 ? gender[u] : gender[targ];
    for (i = g[u][0]; i <= g[u][1] && g >= 0; ++i)
        if (gender[E[i].id2] == gend) {
            path[l] = i;
            search(E[i].id2, targ, l + 1);
        }
    visited[u] = 0;
}

int main() {
    int i, j, k, u, v;
    char id1[8], id2[8];
    freopen("input", "r", stdin);
    memset(g, -1, sizeof(g));
    scanf("%d %d", &n, &m);
    for (j = i = 0; i < m; ++i) {
        scanf("%s %s", id1, id2);
        sscanf(id1, "%d", &u);
        sscanf(id2, "%d", &v);
        u < 0 ? (u = -u) : 0;
        v < 0 ? (v = -v) : 0;
        E[j].id1 = u;
        E[j++].id2 = v;
        E[j].id1 = v;
        E[j++].id2 = u;
        gender[u] = id1[0] == '-';
        gender[v] = id2[0] == '-';
    }
    qsort(E, m <<= 1, sizeof(struct pair), cmp);
    g[E[0].id1][0] = 0;
    for (i = 1; i < m - 1; ++i) {
        if (E[i].id1 != E[i + 1].id1) {
            g[E[i].id1][1] = i;
            g[E[i + 1].id1][0] = i + 1;
        }
    }
    g[E[i].id1][1] = m - 1;
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &u, &v);
        count = 0;
        search(u < 0 ? -u : u, v < 0 ? -v : v, 0);
        printf("%d\n", count);
        for (i = 0; i < count; ++i)
            printf("%04d %04d\n", E[ans[i]].id1, E[ans[i]].id2);
    }
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pair {
    int id1, id2;
} ans[90000];

int cmp(const void *a, const void *b) {
    struct pair *pa = (struct pair *)a, *pb = (struct pair *)b;
    return pa->id1 != pb->id1 ? pa->id1 - pb->id1 : pa->id2 - pb->id2;
}

int n, m, id2vn[10000], vn2id[301], gender[301], g[301][301], visited[301], count, path[4];

void dfs(int u, int targ, int l) {
    if (visited[u])
        return;
    if (l == 3) {
        if (u == targ) {
            ans[count].id1 = path[1];
            ans[count++].id2 = path[2];
        }
        return;
    }
    visited[u] = 1;
    path[l] = vn2id[u];
    int i, gend = l == 0 ? gender[u] : gender[targ];
    for (i = 1; i <= g[u][0]; ++i)
        if (gender[g[u][i]] == gend)
            dfs(g[u][i], targ, l + 1);
    visited[u] = 0;
}

int main() {
    int i, j, k, u, v, vn = 0;
    char id1[8], id2[8];
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%s %s", id1, id2);
        sscanf(id1, "%d", &u);
        sscanf(id2, "%d", &v);
        u < 0 ? (u = -u) : 0;
        v < 0 ? (v = -v) : 0;
        if (!id2vn[u]) {
            id2vn[u] = ++vn;
            vn2id[vn] = u;
            gender[vn] = id1[0] == '-';
        }
        if (!id2vn[v]) {
            id2vn[v] = ++vn;
            vn2id[vn] = v;
            gender[vn] = id2[0] == '-';
        }
        g[id2vn[u]][++g[id2vn[u]][0]] = id2vn[v];
        g[id2vn[v]][++g[id2vn[v]][0]] = id2vn[u];
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &u, &v);
        u < 0 ? (u = -u) : 0;
        v < 0 ? (v = -v) : 0;
        count = 0;
        dfs(id2vn[u], id2vn[v], 0);
        qsort(ans, count, sizeof(struct pair), cmp);
        printf("%d\n", count);
        for (i = 0; i < count; ++i)
            printf("%04d %04d\n", ans[i].id1, ans[i].id2);
    }
    return 0;
}
*/
