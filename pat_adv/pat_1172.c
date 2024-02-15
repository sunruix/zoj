#include <stdio.h>

typedef struct {
    int w, c, m;
} point;

int main() {
    int n, m, i, j, w, ans = 0;
    point a[10001];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        a[i].c = 1;
        a[i].m = 0;
    }
    scanf("%d", &a[0].w);
    for (j = i = 1; i < n; ++i) {
        scanf("%d", &w);
        if (w == a[j - 1].w)
            ++a[j - 1].c;
        else
            a[j++].w = w;
    }
    m = j;
    for (i = 0; i < m; ++i) {
        if ((i == 0 || a[i].w < a[i - 1].w) && (i == m - 1 || a[i].w < a[i + 1].w)) {
            for (j = i; j > 0 && a[j].w < a[j - 1].w; --j) {
                if (a[j - 1].m < a[j].m + 100)
                    a[j - 1].m = a[j].m + 100;
            }
            for (j = i; j < m - 1 && a[j].w < a[j + 1].w; ++j) {
                if (a[j + 1].m < a[j].m + 100)
                    a[j + 1].m = a[j].m + 100;
            }
        }
    }
    for (i = 0; i < m; ++i)
        ans += a[i].m * a[i].c;
    printf("%d\n", ans + n * 200);
    return 0;
}
