#include <stdio.h>
#include <string.h>

typedef struct {
    int score, voucher;
} edge;

int n, m, k, g[1024][1024], path[1024];
char instack[1024], visited[1024];
edge E[1024][1024], dist[1024];

int dfs(int v) {
    if (instack[v])
        return 0;
    if (visited[v])
        return 1;
    instack[v] = 1;
    for (int i = 1; i <= g[v][0]; ++i)
        if (!dfs(g[v][i]))
            return 0;
    return visited[v] = !(instack[v] = 0);
}

int dijk(int src) {
    int u, v, min, max, x, y;
    char known[1024] = {0};
    edge d[1024];
    for (v = 0; v < n; ++v) {
        d[v].score = 0x7fffffff;
        d[v].voucher = 0;
    }
    d[src].score = 0;
    u = src;
    while (1) {
        visited[u] = known[u] = 1;
        for (int i = 1; i <= g[u][0]; ++i) {
            v = g[u][i];
            x = d[u].score + E[u][v].score;
            y = d[u].voucher + E[u][v].voucher;
            if (x < d[v].score || (x == d[v].score && y > d[v].voucher)) {
                d[v].score = x;
                d[v].voucher = y;
                if (x < dist[v].score || (x == dist[v].score && y > dist[v].voucher)) {
                    dist[v] = d[v];
                    path[v] = u;
                }
            }
        }
        min = 0x7FFFFFFF;
        max = 0;
        u = -1;
        for (v = 0; v < n; ++v) {
            if (!known[v] && (d[v].score < min || (d[v].score == min && d[v].voucher > max))) {
                min = d[v].score;
                max = d[v].voucher;
                u = v;
            }
        }
        if (u == -1)
            break;
    }
    return 1;
}

int main() {
    int i, j, u, v, w, yes, p[1024];
    memset(path, -1, sizeof(path));
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        g[u][++g[u][0]] = v;
        scanf("%d %d", &E[u][v].score, &E[u][v].voucher);
        path[v] = u;
    }
    for (yes = 1, v = 0; v < n && yes; ++v)
        yes = dfs(v);
    for (v = 0; yes && v < n; ++v) {
        dist[v].score = 0x7fffffff;
        dist[v].voucher = 0;
    }
    for (v = 0; yes && v < n; ++v) {
        if (path[v] == -1)
            dijk(v);
    }
    printf("%s\n", yes ? "Okay." : "Impossible.");
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &v);
        if (path[v] == -1)
            printf("You may take test %d directly.\n", v);
        else {
            if (!yes)
                printf("Error.\n");
            else {
                i = 0;
                while (v != -1)
                    v = path[p[i++] = v];
                for (j = i - 1; j > 0; --j)
                    printf("%d->", p[j]);
                printf("%d\n", p[0]);
            }
        }
    }
    return 0;
}
