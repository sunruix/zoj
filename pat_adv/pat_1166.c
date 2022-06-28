#include <stdio.h>

int main() {
    int n, m, i, j, k, l, u, v, g[256][8] = {0}, a[8] = {0}, b[8] = {0};
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &u, &v);
        g[v][u >> 5] |= 1 << (u & 0x1F);
        g[u][v >> 5] |= 1 << (v & 0x1F);
    }
    for (i = 1; i <= n; ++i)
        g[i][i >> 5] |= 1 << (i & 0x1F);
    scanf("%d", &k);
    for (j = 1; j <= k; ++j) {
        for (i = 0; i < 8; ++i)
            b[i] = ~(a[i] = 0);
        scanf("%d", &l);
        while (l--) {
            scanf("%d", &u);
            a[u >> 5] |= 1 << (u & 0x1F);
            for (i = 0; i < 8; ++i)
                b[i] &= g[u][i];
        }
        printf("Area %d ", j);
        for (i = 0; i < 8; ++i)
            if (a[i] != b[i] && (a[i] & b[i]) != a[i])
                    break;
        if (i < 8)
            printf("needs help.\n");
        else {
            for (i = 0; i < 8 && a[i] == b[i]; ++i);
            if (i == 8)
                printf("is OK.\n");
            else {
                u = a[i] ^ b[i];
                for (v = 0; !((u >> v) & 1); ++v);
                printf("may invite more people, such as %d.\n", (i << 5) + v);
            }
        }
    }
    return 0;
}

