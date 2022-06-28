#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int zone, bday, y;
    char z;
} id;

int comp(id *pa, id *pb) {
    if (pa->bday != pb->bday)
        return pa->bday - pb->bday;
    if (pa->zone != pb->zone)
        return pa->zone - pb->zone;
    if (pa->y != pb->y)
        return pa->y - pb->y;
    return pa->z - pb->z;
}

int cmp(const void *a, const void *b) {
    return comp((id *)a, (id *)b);
}

int main() {
    int n, m, i, j, k, count = 0, dif;
    id a[100000], b[100000], *oldest = NULL;
    freopen("input", "r", stdin);
    scanf("%d\n", &n);
    for (i = 0; i < n; ++i)
        scanf("%6d%8d%3d%c\n", &a[i].zone, &a[i].bday, &a[i].y, &a[i].z);
    qsort(a, n, sizeof(id), cmp);
    scanf("%d\n", &m);
    for (i = 0; i < m; ++i)
        scanf("%6d%8d%3d%c\n", &b[i].zone, &b[i].bday, &b[i].y, &b[i].z);
    qsort(b, m, sizeof(id), cmp);
    i = j = 0;
    while (i < n && j < m) {
        dif = cmp(a + i, b + j);
        if (dif > 0)
            ++j;
        else if (dif < 0)
            ++i;
        else {
            if (!count)
                oldest = a + i;
            ++count;
            ++i;
            ++j;
        }
    }
    if (!count)
        oldest = b;
    printf("%d\n%06d%08d%03d%c\n", count, oldest->zone, oldest->bday, oldest->y, oldest->z);
    return 0;
}
