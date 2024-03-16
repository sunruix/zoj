#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node *left;
    struct node *right;
};

struct node *make_tree(int *in, int *pre, int len) {
    if (!len)
        return NULL;
    int i;
    struct node *n = malloc(sizeof(struct node));
    n->item = pre[0];
    for (i = 0; in[i] != pre[0]; ++i);
    n->left = make_tree(in, pre + 1, i);
    n->right = make_tree(in + i + 1, pre + i + 1, len - i - 1);
    return n;
}

int main() {
    int n, m, i, j, k, in[32], pre[32], ans[32];

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &in[i]);
    for (i = 0; i < n; ++i)
        scanf("%d", &pre[i]);
    struct node *root = make_tree(in, pre, n);
    struct node *q[64] = {NULL}, *x;
    i = j = k = 0;
    q[i++] = root;
    q[i++] = NULL;
    printf("%d", root->item);
    while (i != j) {
        x = q[j++];
        if (!x) {
            if (q[j]) {
                printf(" %d", q[j]->item);
                q[i++] = NULL;
            }
            else
                break;
        }
        else {
            if (x->left)
                q[i++] = x->left;
            if (x->right)
                q[i++] = x->right;
        }
    }
    printf("\n");
    return 0;
}

