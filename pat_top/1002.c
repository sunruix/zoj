#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int p, l, d;
} record;

int cmp(const void *a, const void *b) {
    record *pa = (record *)a, *pb = (record *)b;
    return pa->d - pb->d;
}

int main() {
    int n, i, j, k, *dp[64], maxd = 0, ans = 0;
    record a[64];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d %d %d", &a[i].p, &a[i].l, &a[i].d);
        if (maxd < a[i].d)
            maxd = a[i].d;
    }
    qsort(a + 1, n, sizeof(record), cmp);
    for (i = 0; i <= n; ++i)
        dp[i] = calloc(maxd + 1, sizeof(int));
    for (j = 0; j <= maxd; ++j) {
        for (i = 1; i <= n; ++i) {
            if (j <= a[i].d && j >= a[i].l)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].l] + a[i].p);
            else
                dp[i][j] = dp[i - 1][j];
        }
        ans = max(ans, dp[n][j]);
    }
    printf("%d\n", ans);
    return 0;
}
