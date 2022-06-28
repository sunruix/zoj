#include <stdio.h>
#include <string.h>

typedef struct {
    int left, right, level;
} node;

node tree[1024];

int build(int *post, int *in, int len, int level) {
    if (!len)
        return 0;
    if (len == 1) {
        tree[*post].level = level;
        return *post;
    }
    int i, j, k, root = post[len - 1];
    for (i = 0; in[i] != root && i < len; ++i);
    tree[root].left = build(post, in, i, level + 1);
    tree[root].right = build(post + i, in + i + 1, len - i - 1, level + 1);
    tree[root].level = level;
    return root;
}

int trav(int root, int a, int b, int (*f)(int, int, int)) {
    if (!root)
        return 0;
    if (f(root, a, b))
        return 1;
    return trav(tree[root].left, a, b, f) || trav(tree[root].right, a, b, f);
}

int sibling(int root, int a, int b) {
    return (tree[root].left == a && tree[root].right == b) || (tree[root].right == a && tree[root].left == b);
}

int lchild(int root, int a, int b) {
    return root == b && tree[root].left == a;
}

int rchild(int root, int a, int b) {
    return root == b && tree[root].right == a;
}

int parent(int root, int a, int b) {
    return lchild(root, b, a) || rchild(root, b, a);
}

int notfull(int root, int a, int b) {
    return (tree[root].left && !tree[root].right) || (tree[root].right && !tree[root].left);
}

int main() {
    int n, m, post[32], in[32], root, i, j, k, a, b, full, yes;
    char s[128] = {0};
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &post[i]);
    for (i = 0; i < n; ++i)
        scanf("%d", &in[i]);
    root = build(post, in, n, 0);
    full = !trav(root, 0, 0, notfull);
    scanf("%d\n", &m);
    while (m--) {
        fgets(s, sizeof(s), stdin);
        if (strstr(s, "root")) {
            sscanf(s, "%d", &a);
            yes = a == root;
        }
        else if (strstr(s, "siblings")) {
            sscanf(s, "%d and %d", &a, &b);
            yes = trav(root, a, b, sibling);
        }
        else if (strstr(s, "parent")) {
            sscanf(s, "%d is the parent of %d", &a, &b);
            yes = trav(root, a, b, parent);
        }
        else if (strstr(s, "left")) {
            sscanf(s, "%d is the left child of %d", &a, &b);
            yes = trav(root, a, b, lchild);
        }
        else if (strstr(s, "right")) {
            sscanf(s, "%d is the right child of %d", &a, &b);
            yes = trav(root, a, b, rchild);
        }
        else if (strstr(s, "level")) {
            sscanf(s, "%d and %d", &a, &b);
            yes = tree[a].level == tree[b].level;
        }
        else if (strstr(s, "full"))
            yes = full;
        printf("%s\n", yes ? "Yes" : "No");
    }
    return 0;
}
