#include <stdio.h>

typedef struct {
    int val, next;
} node;

int main() {
    int n, head, addr, val, next, i, k, v[10001] = {0}, p1, p2, p3, dhead;
    node list[100000];
    freopen("input", "r", stdin);
    scanf("%d %d", &head, &n);
    for (i = 0; i < n; ++i) {
        scanf("%d %d %d", &addr, &val, &next);
        list[addr].val = val;
        list[addr].next = next;
    }
    k = list[head].val > 0 ? list[head].val : -list[head].val;
    v[k] = 1;
    for (p1 = head, p2 = list[p1].next, dhead = -1; p2 != -1; p2 = list[p1].next) {
        k = list[p2].val > 0 ? list[p2].val : -list[p2].val;
        if (!v[k]) {
            v[k] = 1;
            p1 = p2;
        }
        else {
            list[p1].next = list[p2].next;
            dhead == -1 ? (dhead = p2) : (list[p3].next = p2);
            p3 = p2;
            list[p3].next = -1;
        }
    }
    for (p1 = head; list[p1].next != -1; p1 = list[p1].next)
        printf("%05d %d %05d\n", p1, list[p1].val, list[p1].next);
    printf("%05d %d -1\n", p1, list[p1].val);
    if (dhead >= 0) {
        for (p1 = dhead; list[p1].next != -1; p1 = list[p1].next)
            printf("%05d %d %05d\n", p1, list[p1].val, list[p1].next);
        printf("%05d %d -1\n", p1, list[p1].val);
    }
    return 0;
}
