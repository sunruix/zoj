#include <stdio.h>

int main() {
    int n, i, j, k, start, addr, data, next, rindex[100000], offset;
    struct node {
        int next, data;
    } list[100000];
    freopen("input", "r", stdin);
    scanf("%d %d %d", &start, &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d", &addr);
        scanf("%d %d", &list[addr].data, &list[addr].next);
    }
    for (n = 0, i = start; i != -1; i = list[i].next, ++n);
    for (offset = 0, j = start; offset + k <= n; offset += k)
        for (i = k - 1; i >= 0; --i, j = list[j].next)
            rindex[offset + i] = j;
    next = list[rindex[offset - k]].next;
    for (i = 0; i < offset - 1; ++i)
        list[rindex[i]].next = rindex[i + 1];
    list[rindex[offset - 1]].next = next;
    for (i = rindex[0]; list[i].next != -1; i = list[i].next)
        printf("%05d %d %05d\n", i, list[i].data, list[i].next);
    printf("%05d %d -1\n", i, list[i].data);
    return 0;
}
