#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int ge(int *a, int l, int r, int x) {
    int m = (l + r) >> 1;
    while (l != r) {
        a[m] >= x ? (r = m) : (l = m + 1);
        m = (l + r) >> 1;
    }
    return m;
}

int main() {
    int n, i, j, p, q, r, M, m, a[100000], ans = 0;
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &p);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for (i = n - 1; i >= ans; --i) {
        j = a[i] <= p ? 0 : ge(a, 0, i, a[i] / p + (a[i] % p ? 1 : 0));
        if (i - j + 1 > ans)
            ans = i - j + 1;
    }
    printf("%d\n", ans);
}
