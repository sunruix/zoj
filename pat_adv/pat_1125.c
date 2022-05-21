#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, i, l, a[10000];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for (l = a[0], i = 1; i < n; ++i)
        l = l + a[i] >> 1;
    printf("%d\n", l);
    return 0;
}
