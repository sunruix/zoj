#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, i, a[100000], b, ans = 0;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for (i = n - 1; i >= 0; --i) {
        b = a[i] - 1 > n - i ? n - i : a[i] - 1;
        ans = ans > b ? ans : b;
    }
    printf("%d\n", ans);
    return 0;
}
