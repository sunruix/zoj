#include <stdio.h>

typedef struct {
    int l, r;
} tree;

int getmin(int *a, int l, int r) {
    int min = 0x7FFFFFFF, i, j;
    for (i = j = l; i < r; ++i)
        if (min > a[i])
            min = a[j = i];
    return min == 0x7FFFFFFF ? -1 : j;
}

int main() {
    int n, m, i, j, k, a[32], b[32], head = 0, tail = 0, pos;
    tree q[64], t;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    i = 0;
    t.l = 0;
    t.r = n;
    q[tail++] = t;
    while (head != tail) {
        t = q[head++];
        if ((pos = getmin(a, t.l, t.r)) != -1) {
            b[i++] = a[pos];
            q[tail].l = t.l;
            q[tail++].r = pos;
            q[tail].l = pos + 1;
            q[tail++].r = t.r;
        }
    }
    for (i = 0; i < n - 1; ++i)
        printf("%d ", b[i]);
    printf("%d\n", b[i]);
    return 0;
}
