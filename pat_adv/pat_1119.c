#include <stdio.h>

typedef struct {
    int left, right;
} node;
node t[100000];
int n, pre[32], post[32], yes = 1, seq[32], idx;

void inorder(int root) {
    if (!root)
        return;
    inorder(t[root].left);
    seq[idx++] = root;
    inorder(t[root].right);
}

void deter(int root, int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2)
        return;
    int i, j;
    if (pre[l1] != post[r2]) {
        t[root].left = pre[l1];
        t[root].right = post[r2];
        for (i = l1 + 1; i <= r1 && pre[i] != post[r2]; ++i);
        for (j = l2; j <= r2 && post[j] != pre[l1]; ++j);
        deter(pre[l1], l1 + 1, i - 1, l2, j - 1);
        deter(post[r2], i + 1, r1, j + 1, r2 - 1);
    }
    else {
        yes = 0;
        t[root].left = pre[l1];
        deter(pre[l1], l1 + 1, r1, l2, r2 - 1);
    }
}

int main() {
    int n, i, j, l, r, root;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &pre[i]);
    for (i = 0; i < n; ++i)
        scanf("%d", &post[i]);
    root = pre[0];
    deter(root, 1, n - 1, 0, n - 2);
    inorder(root);
    printf("%s\n", yes ? "Yes" : "No");
    for (i = 0; i < n - 1; ++i)
        printf("%d ", seq[i]);
    printf("%d\n", seq[i]);
    return 0;
}
