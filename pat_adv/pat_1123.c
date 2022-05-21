#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val, height;
    struct node *left, *right;
} *avl;

avl new(int x) {
    avl n = malloc(sizeof(*n));
    n->val = x;
    n->left = n->right = NULL;
    return n;
}

int height(avl t) {
    if (!t)
        return 0;
    int hl = height(t->left), hr = height(t->right);
    return 1 + (hl > hr ? hl : hr);
}

avl rotate_left(avl t) {
    avl nt = t->right;
    t->right = nt->left;
    nt->left = t;
    return nt;
}

avl rotate_right(avl t) {
    avl nt = t->left;
    t->left = nt->right;
    nt->right = t;
    return nt;
}

avl rotate_lr(avl t) {
    t->left = rotate_left(t->left);
    return rotate_right(t);
}

avl rotate_rl(avl t) {
    t->right = rotate_right(t->right);
    return rotate_left(t);
}

avl balance(avl t) {
    if (!t)
        return t;
    int hl = height(t->left), hr = height(t->right);
    if (hl - hr > 1) {
        if (height(t->left->left) > height(t->left->right))
            t = rotate_right(t);
        else
            t = rotate_lr(t);
    }
    else if (hr - hl > 1) {
        if (height(t->right->right) > height(t->right->left))
            t = rotate_left(t);
        else
            t = rotate_rl(t);
    }
    return t;
}

avl insert(avl t, int x) {
    if (!t)
        t = new(x);
    else if (x == t->val)
        return t;
    else if (x < t->val)
        t->left = insert(t->left, x);
    else
        t->right = insert(t->right, x);
    return balance(t);
}

int main() {
    int n, i, j, k, x, head = 0, tail = 0, yes = 1;
    avl t = NULL, node, q[128] = {NULL};
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        t = insert(t, x);
    }
    q[tail++] = t;
    while (head != tail) {
        node = q[head++];
        if (node) {
            q[tail++] = node->left;
            q[tail++] = node->right;
        }
    }
    printf("%d", t->val);
    for (j = 1, i = 1; i < tail && j < n; ++i) {
        if (q[i]) {
            printf(" %d", q[i]->val);
            ++j;
        }
        else
            yes = 0;
    }
    printf("\n%s\n", yes ? "YES" : "NO");
    return 0;
}

