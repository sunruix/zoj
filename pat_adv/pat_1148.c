#include <stdio.h>

#define pos(i) ((i) >= 0 ? (i) : -(i))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n, i, j, k, said[128] = {0}, iswolf[128] = {0}, wolf[2] = {0xFF, 0xFF}, count, u, v;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%d", &said[i]);
    for (i = 1; i <= n; ++i) {
        if (said[i] == -i)
            continue;
        u = i;
        iswolf[i] = 1;
        said[i] = -said[i];
        for (j = 1; j <= n; ++j) {
            if (j == i)
                continue;
            iswolf[j] = -1;
            said[j] = -said[j];
            for (k = 1; k <= n; ++k) {
                if (!iswolf[pos(said[k])])
                    iswolf[pos(said[k])] = said[k] < 0 ? 1 : -1;
                else if ((said[k] > 0 && iswolf[said[k]] == 1) || (said[k] < 0 && iswolf[-said[k]] == -1))
                    break;
            }
            if (k > n) {
                for (v = 0, k = 1; k <= n; ++k)
                    if (iswolf[k] == 1 && k != u)
                        v = !v ? k : 0xFF;
                for (k = 1; k <= n && !v; ++k)
                    if (!iswolf[k])
                        v = k;
                if (v && v != 0xFF) {
                    if (wolf[0] > min(u, v) || (wolf[0] == min(u, v) && wolf[1] > max(u, v))) {
                        wolf[0] = min(u, v);
                        wolf[1] = max(u, v);
                    }
                }
            }
            for (k = 1; k <= n; ++k)
                if (k != i)
                    iswolf[k] = 0;
            said[j] = -said[j];
        }
        said[i] = -said[i];
        iswolf[i] = 0;
    }
    if (wolf[0] <= n)
        printf("%d %d\n", wolf[0], wolf[1]);
    else
        printf("No Solution\n");
    return 0;
}
