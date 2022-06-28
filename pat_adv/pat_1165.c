#include <stdio.h>

typedef struct {
    int val, next;
} node;

node list[100000];

int reverse(int head, int k) {
    int p0 = -1, p1 = head, p2, p3, i;
    while (p1 != -1) {
        for (i = 1, p2 = p1; i < k && list[p2].next != -1; ++i, p2 = list[p2].next);
        p3 = list[p2].next;
        list[p2].next = p0;
        p0 = p1;
        p1 = p3;
    }
    return p0;
}

int main() {
    int n, m, i, j, k, head, addr;
    freopen("input", "r", stdin);
    scanf("%d %d %d", &head, &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d", &addr);
        scanf("%d %d", &list[addr].val, &list[addr].next);
    }
    head = reverse(head, k);
    for (; list[head].next != -1; head = list[head].next)
        printf("%05d %d %05d\n", head, list[head].val, list[head].next);
    printf("%05d %d -1\n", head, list[head].val);
    return 0;
}
