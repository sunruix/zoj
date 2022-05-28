#include <stdio.h>

int main() {
    struct {
        int val, next;
    } list[100000];
    int n, i, j, k, addr, head, p, neg[100000], ks[100000], oth[100000], nneg = 0, nks = 0, noth = 0;
    freopen("input", "r", stdin);
    scanf("%d %d %d", &head, &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d", &addr);
        scanf("%d %d", &list[addr].val, &list[addr].next);
    }
    for (p = head; p != -1; p = list[p].next) {
        if (list[p].val < 0)
            neg[nneg++] = p;
        else if (list[p].val > k)
            oth[noth++] = p;
        else
            ks[nks++] = p;
    }
    for (i = 0; i < nks; ++i)
        neg[nneg++] = ks[i];
    for (i = 0; i < noth; ++i)
        neg[nneg++] = oth[i];
    for (i = 0; i < nneg - 1; ++i)
        printf("%05d %d %05d\n", neg[i], list[neg[i]].val, neg[i + 1]);
    printf("%05d %d -1\n", neg[i], list[neg[i]].val);
    return 0;
}
