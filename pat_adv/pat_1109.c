#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[16];
    int height;
} info;

int cmp(const void *a, const void *b) {
    info *pa = (info *)a, *pb = (info *)b;
    if (pa->height != pb->height)
        return pb->height - pa->height;
    return strcmp(pa->name, pb->name);
}

int main() {
    int n, k, i, j, l, m, p, q, r, row[10000], idx = 0;
    info a[10000];
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i)
        scanf("%s %d", a[i].name, &a[i].height);
    qsort(a, n, sizeof(info), cmp);
    m = n / k;
    r = n % k;
    for (l = m + r, i = 0; i < k; ++i, l = m) {
        row[j = l >> 1] = idx++;
        for (p = 1; j - p >= 0; ++p) {
            if (j - p >= 0)
                row[j - p] = idx++;
            if (j + p < l)
                row[j + p] = idx++;
        }
        for (j = 0; j < l - 1; ++j)
            printf("%s ", a[row[j]].name);
        printf("%s\n", a[row[j]].name);
    }
    return 0;
}
