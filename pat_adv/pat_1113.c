#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, i, m, sum1 = 0, sum2 = 0, a[100000];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    m = n >> 1;
    for (i = 0; i < m; sum1 += a[i++]);
    for (; i < n; sum2 += a[i++]);
    printf("%d %d\n", n & 1, sum2 - sum1);
    return 0;
}
