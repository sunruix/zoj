#include <stdio.h>

int main() {
    int n, i, j, k, a[100000], b[100000], max, min, bn = 0;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (max = a[0], i = 1; i < n; ++i)
        a[i] >= max ? (max = a[i]) : (a[i] = -a[i]);
    min = a[n - 1] > 0 ? a[n - 1] : -a[n - 1];
    for (i = n - 1; i >= 0; --i) {
        k = a[i] > 0 ? a[i] : -a[i];
        k <= min ? (min = k) : (a[i] = a[i] > 0 ? -a[i] : a[i]);
        if (a[i] > 0)
            b[bn++] = a[i];
    }
    printf("%d\n", bn);
    if (bn) {
        for (i = bn - 1; i > 0; --i)
            printf("%d ", b[i]);
        printf("%d", b[i]);
    }
    printf("\n");
    return 0;
}
