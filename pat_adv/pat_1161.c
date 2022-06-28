#include <stdio.h>

#define swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

typedef struct {
    int val, next;
} node;

int length(node *list, int head) {
    int len = 0;
    while (head != -1) {
        len++;
        head = list[head].next;
    }
    return len;
}

int reverse(node *list, int head) {
    int p0 = -1, p1 = head, p2;
    while (p1 != -1) {
        p2 = list[p1].next;
        list[p1].next = p0;
        p0 = p1;
        p1 = p2;
    }
    return p0;
}

int main() {
    int n, i, j, k, addr, head, head1, head2, len1, next1, next2;
    node list[100000];
    freopen("input", "r", stdin);
    scanf("%d %d %d", &head1, &head2, &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &addr);
        scanf("%d %d", &list[addr].val, &list[addr].next);
    }
    len1 = length(list, head1);
    if (len1 * 3 <= n)
        swap(head1, head2);
    head = head1;
    head2 = reverse(list, head2);
    for (i = 0; head2 != -1; head1 = next1) {
        next1 = list[head1].next;
        if ((i++) & 1) {
            next2 = list[head2].next;
            list[head1].next = head2;
            list[head2].next = next1;
            head2 = next2;
        }
    }
    for (; list[head].next != -1; head = list[head].next)
        printf("%05d %d %05d\n", head, list[head].val, list[head].next);
    printf("%05d %d -1\n", head, list[head].val);
    return 0;
}
