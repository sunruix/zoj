#include <stdio.h>

#define index(u) (u >> 5)
#define bit(u) (1 << (u & 0x1F))

int main() {
    int nv, ne, m, i, k, j, u, v, g[256][8] = {0}, a[8], b[8], c[8], yes;
    freopen("input", "r", stdin);
    scanf("%d %d", &nv, &ne);
    for (i = 1; i <= nv; ++i)
        g[i][index(i)] |= bit(i);
    while (ne--) {
        scanf("%d %d", &u, &v);
        g[u][index(v)] |= bit(v);
        g[v][index(u)] |= bit(u);
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &k);
        for (i = 0; i < 8; ++i)
            b[i] = ~(a[i] = 0);
        for (i = 0; i < k; ++i) {
            scanf("%d", &v);
            for (j = 0; j < 8; ++j)
                b[j] &= g[v][j];
            a[index(v)] |= bit(v);
        }
        yes = 1;
        for (i = 0; i < 8; ++i)
            a[i] == b[i] ? (c[i] = a[i]) : (yes = 0, c[i] = a[i] & b[i]);
        if (yes)
            printf("Yes\n");
        else {
            for (i = 0; i < 8 && a[i] == c[i]; ++i);
            printf("%s\n", i == 8 ? "Not Maximal" : "Not a Clique");
        }
    }
    return 0;
}
