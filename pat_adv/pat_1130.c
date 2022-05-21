#include <stdio.h>
#include <string.h>

struct node {
    int left, right;
    char data[1024];
} tree[32];

void infix(int root) {
    if (root == -1 || (tree[root].left == -1 && tree[root].right == -1))
        return;
    char buf[1024] = {0};
    infix(tree[root].left);
    infix(tree[root].right);
    sprintf(buf, "(%s%s%s)", tree[root].left == -1 ? "" : tree[tree[root].left].data,
            tree[root].data,
            tree[root].right == -1 ? "" : tree[tree[root].right].data);
    strcpy(tree[root].data, buf);
}

int main() {
    int n, i, root, sum;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (sum = 0, i = 1; i <= n; ++i) {
        scanf("%s %d %d", &tree[i].data, &tree[i].left, &tree[i].right);
        if (tree[i].left > 0)
            sum += tree[i].left;
        if (tree[i].right > 0)
            sum += tree[i].right;
    }
    root = (n * (n + 1) >> 1) - sum;
    infix(root);
    if (n > 1) {
        tree[root].data[strlen(tree[root].data) - 1] = '\0';
        printf("%s\n", tree[root].data + 1);
    }
    else
        printf("%s\n", tree[root].data);
    return 0;
}
