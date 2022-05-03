#include <stdio.h>

#define swap(a, b) ((a)^=(b), (b)^=(a), (a)^=(b))

typedef struct {
    int left, right;
} node;

int n, pos, a[16];
node tree[16];

void invert(int root) {
    if (root == -1)
        return;
    invert(tree[root].left);
    invert(tree[root].right);
    swap(tree[root].left, tree[root].right);
}

void inorder(int root) {
    if (root == -1)
        return;
    inorder(tree[root].left);
    a[pos++] = root;
    inorder(tree[root].right);
}

int main() {
    int i, root, q[16], head = 0, tail = 0, x;
    char l, r;
    freopen("input", "r", stdin);
    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        scanf("%c %c\n", &l, &r);
        tree[i].left = l == '-' ? -1 : l - '0';
        tree[i].right = r == '-' ? -1 : r - '0';
        if (l != '-')
            a[l - '0'] = 1;
        if (r != '-')
            a[r - '0'] = 1;
    }
    for (i = 0; i < n && a[i]; ++i);
    root = i;
    invert(root);
    q[tail++] = root;
    i = 0;
    while (head != tail) {
        a[i++] = (x = q[head++]);
        if (tree[x].left >= 0)
            q[tail++] = tree[x].left;
        if (tree[x].right >= 0)
            q[tail++] = tree[x].right;
    }
    for (i = 0; i < n - 1; ++i)
        printf("%d ", a[i]);
    printf("%d\n", a[i]);
    inorder(root);
    for (i = 0; i < n - 1; ++i)
        printf("%d ", a[i]);
    printf("%d\n", a[i]);
    return 0;
}

