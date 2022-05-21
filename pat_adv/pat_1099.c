#include <stdio.h>
#include <stdlib.h>

struct {
    int left, right, val;
} nodes[128];
int n, i, j, x, y, a[128], b[128], q[128], head, tail, pos;

void bst(int r) {
    if (r == -1)
        return;
    bst(nodes[r].left);
    nodes[r].val = a[pos++];
    bst(nodes[r].right);
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d %d", &nodes[i].left, &nodes[i].right);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    bst(0);
    j = 0;
    q[tail++] = 0;
    q[tail++] = -1;
    while (1) {
        x = q[head++];
        if (x == -1) {
            if (head == tail)
                break;
            else
                q[tail++] = -1;
        }
        else {
            b[j++] = nodes[x].val;
            y = nodes[x].left;
            if (y > 0)
                q[tail++] = y;
            y = nodes[x].right;
            if (y > 0)
                q[tail++] = y;
        }
    }
    for (i = 0; i < n - 1; ++i)
        printf("%d ", b[i]);
    printf("%d\n", b[i]);
    return 0;
}
