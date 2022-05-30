#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, k, i, j, a[100001] = {0}, x;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0, k = 1; i < n; ++i) {
        scanf("%d", &x);
        if (x > 0)
            a[k++] = x;
    }
    qsort(a, k, sizeof(int), cmp);
    for (i = 1; i < k && a[i] - a[i - 1] <= 1; ++i);
    printf("%d\n", a[i - 1] + 1);
    return 0;
}
