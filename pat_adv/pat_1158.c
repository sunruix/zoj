#include <stdio.h>

int out[1024], back[1024], g[1024][1024], s[1024], susp[1024], ptr[1024];

int find(int x) {
    while (s[x])
        x = s[x];
    return x;
}

void un(int x, int y) {
    int rx = find(x), ry = find(y);
    s[rx] = ry;
}

int main() {
    int n, m, i, j, k, u, v, l, sn = 0;
    freopen("input", "r", stdin);
    scanf("%d %d %d", &k, &n, &m);
    while (m--) {
        scanf("%d %d %d", &u, &v, &l);
        g[u][v] += l;
    }
    for (u = 1; u <= n; ++u) {
        for (v = 1; v <= n; ++v) {
            if (g[u][v]) {
                if (g[u][v] <= 5)
                    ++out[u];
                if (g[v][u] && g[v][u] <= 5)
                    ++back[v];
            }
        }
    }
    for (u = 1; u <= n; ++u) {
        if (out[u] > k && out[u] >= 5 * back[u]) {
            susp[sn++] = u;
            for (i = 0; i < sn - 1; ++i)
                if (g[u][susp[i]] && g[susp[i]][u])
                    un(u, susp[i]);
        }
    }
    if (!sn)
        printf("None\n");
    else {
        for (i = 0; i < sn; ++i) {
            if (ptr[susp[i]])
                continue;
            printf("%d", ptr[susp[i]] = susp[i]);
            for (j = i + 1; j < sn; ++j) {
                if (find(susp[j]) == find(susp[i]))
                    printf(" %d", ptr[susp[j]] = susp[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
