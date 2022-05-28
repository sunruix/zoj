#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
    char rb;
    int bh;
} *tree_node;

tree_node new(int x) {
    tree_node n = malloc(sizeof(*n));
    x > 0 ? (n->val = x, n->rb = 0) : (n->val = -x, n->rb = 1);
    n->left = n->right = NULL;
    n->bh = 0;
    return n;
}

int valid = 1;

tree_node build(int *a, int n) {
    if (n <= 0)
        return NULL;
    int i, bhl, bhr;
    tree_node np = new(a[0]);
    for (i = 1; i < n && np->val > (a[i] > 0 ? a[i] : -a[i]); ++i);
    np->left = build(a + 1, i - 1);
    np->right = build(a + i, n - i);
    if (np->rb && ((np->left && np->left->rb) || (np->right && np->right->rb)))
        valid = 0;
    else {
        bhl = np->left ? (np->left->bh + !np->left->rb) : 0;
        bhr = np->right ? (np->right->bh + !np->right->rb) : 0;
        if (bhl != bhr)
            valid = 0;
        else
            np->bh = bhl;
    }
    return np;
}

int main() {
    int m, n, i, a[32];
    tree_node root = NULL;
    freopen("input", "r", stdin);
    scanf("%d", &m);
    while (m--) {
        valid = 1;
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        root = build(a, n);
        valid = valid && !root->rb;
        printf("%s\n", valid ? "Yes" : "No");
    }
    return 0;
}

