#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, next;
} node;

int cmp(const void *a, const void *b) {
    return (*((node **)a))->val - (*((node **)b))->val;
}

int main() {
    int n, head, i, j, k, addr;
    node a[100001] = {0}, *b[100001] = {0};
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &head);
    for (i = 0; i < n; ++i) {
        scanf("%d", &addr);
        scanf("%d %d", &a[addr].val, &a[addr].next);
    }
    for (n = 0; head != -1; head = a[head].next)
        b[n++] = a + head;
    if (n) {
        qsort(b, n, sizeof(b[0]), cmp);
        printf("%d %05d\n", n, b[0] - a);
        for (i = 0; i < n - 1; ++i)
            printf("%05d %d %05d\n", b[i] - a, b[i]->val, b[i + 1] - a);
        printf("%05d %d -1\n", b[i] - a, b[i]->val);
    }
    else
        printf("0 -1\n");
    return 0;
}
