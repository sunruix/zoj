#include <stdio.h>

int main() {
    int a, b, i, j, k, m, n, w, g[16][1024], s[32768], x;
    char used[200002] = {0}, out[16] = {0};

    scanf("%d %d", &a, &b);
    used[a] = used[b] = 1;
    s[0] = a;
    s[1] = b;
    x = 2;
    scanf("%d %d", &n, &m);
    w = n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            scanf("%d", &g[i][j]);
    for (j = 1; j <= m; ++j) {
        for (i = 1; i <= n; ++i) {
            if (out[i])
                continue;
            out[i] = used[g[i][j]];
            if (!out[i]) {
                for (k = 0; k < x; ++k) {
                    if (used[g[i][j] + s[k]])
                        break;
                }
                out[i] = (k == x);
            }

            if (out[i]) {
                printf("Round #%d: %d is out.\n", j, i);
                --w;
            }
            else {
                used[g[i][j]] = 1;
                s[x++] = g[i][j];
            }
        }
    }
    if (!w)
        printf("No winner.\n");
    else {
        printf("Winner(s):");
        for (i = 1; i <= n; ++i) {
            if (!out[i])
                printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}
