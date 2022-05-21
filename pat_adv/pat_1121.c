#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int search(int x, int *a, int l, int r) {
    int m;
    while (l <= r) {
        m = l + r >> 1;
        if (a[m] == x)
            return m;
        else if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    int n, m, i, j, k, couples[100000] = {0}, guests[10000], ans[10000];
    freopen("input", "r", stdin);
    memset(couples, -1, sizeof(couples));
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &i, &j);
        couples[i] = j;
        couples[j] = i;
    }
    scanf("%d", &m);
    for (i = 0; i < m; ++i)
        scanf("%d", &guests[i]);
    qsort(guests, m, sizeof(int), cmp);
    for (k = 0, i = 0; i < m; ++i) {
        if (couples[guests[i]] == 100000)
            continue;
        else if (couples[guests[i]] == -1 || search(couples[guests[i]], guests, 0, m - 1) == -1)
            ans[k++] = guests[i];
        else
            couples[couples[guests[i]]] = 100000;
    }
    printf("%d\n", k);
    for (i = 0; i < k - 1; ++i)
        printf("%05d ", ans[i]);
    if (k)
        printf("%05d\n", ans[i]);
    return 0;
}
