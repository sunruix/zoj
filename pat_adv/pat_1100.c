#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int left, right, pos;
} node;

int check(node t[], int root) {
    int left = t[root].left, right = t[root].right;
    if (root == -1)
        return 1;
    if (left >= 0 && t[left].pos != (t[root].pos << 1))
        return 0;
    if (right >= 0 && t[right].pos != (t[root].pos << 1) + 1)
        return 0;
    return check(t, left) && check(t, right);
}

int main() {
    int n, i, j, k, root = 0, x, q[32], head = 0, tail = 0, pos = 1;
    node t[32];
    char l[4], r[4];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%s %s", l, r);
        t[i].left = l[0] == '-' ? -1 : atoi(l);
        t[i].right = r[0] == '-' ? -1 : atoi(r);
        root += t[i].left > 0 ? t[i].left : 0;
        root += t[i].right > 0 ? t[i].right : 0;
    }
    root = (n * (n - 1) >> 1) - root;
    q[tail++] = root;
    while (head != tail) {
        t[x = q[head++]].pos = pos++;
        if (t[x].left >= 0)
            q[tail++] = t[x].left;
        if (t[x].right >= 0)
            q[tail++] = t[x].right;
    }
    if(check(t, root))
        printf("YES %d\n", q[head - 1]);
    else
        printf("NO %d\n", root);
    return 0;
}
