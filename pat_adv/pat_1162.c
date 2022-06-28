#include <stdio.h>

typedef struct {
    char data[16], s[256];
    int left, right;
} node;

void postorder(node *tree, int root) {
    int left = tree[root].left, right = tree[root].right;
    char *s = tree[root].s, *ls = NULL, *rs = NULL;
    if (left != -1) {
        postorder(tree, left);
        ls = tree[left].s;
    }
    if (right != -1) {
        postorder(tree, right);
        rs = tree[right].s;
    }
    if (left == -1)
        sprintf(tree[root].s, "(%s%s)", tree[root].data, rs ? rs : "");
    else
        sprintf(tree[root].s, "(%s%s%s)", ls ? ls : "", rs ? rs : "", tree[root].data);
}

int main() {
    int n, root, left, right, i, j, k, sum = 0;
    node tree[32] = {0};
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%s %d %d", tree[i].data, &tree[i].left, &tree[i].right);
        if (tree[i].left != -1)
            sum += tree[i].left;
        if (tree[i].right != -1)
            sum += tree[i].right;
    }
    postorder(tree, root = (n * (n + 1) >> 1) - sum);
    printf("%s\n", tree[root].s);
    return 0;
}
