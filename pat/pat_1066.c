#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

struct node {
    int item;
    struct node *left;
    struct node *right;
};

typedef struct node *avl;

int height(avl t) {
    if (!t)
        return 0;
    return 1 + max(height(t->left), height(t->right));
}

avl rotate_left(avl t) {
    avl new_root = t->right;
    t->right = new_root->left;
    new_root->left = t;
    return new_root;
}

avl rotate_right(avl t) {
    avl new_root = t->left;
    t->left = new_root->right;
    new_root->right = t;
    return new_root;
}

avl rotate_lr(avl t) {
    t->left = rotate_left(t->left);
    return rotate_right(t);
}

avl rotate_rl(avl t) {
    t->right = rotate_right(t->right);
    return rotate_left(t);
}

avl insert(avl t, int x) {
    int hl, hr;
    if (!t) {
        struct node *new = malloc(sizeof(struct node));
        new->item = x;
        new->left = new->right = NULL;
        return new;
    }
    if (x < t->item) {
        t->left = insert(t->left, x);
        if (height(t->left) - height(t->right) > 1) {
            if (height(t->left->left) > height(t->left->right))
                t = rotate_right(t);
            else
                t = rotate_lr(t);
        }
    }
    else {
        t->right = insert(t->right, x);
        if (height(t->right) - height(t->left) > 1) {
            if (height(t->right->right) > height(t->right->left))
                t = rotate_left(t);
            else
                t = rotate_rl(t);
        }
    }
    return t;
}

int main() {
    int n, x;
    avl t = NULL;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        t = insert(t, x);
    }
    printf("%d\n", t->item);
}
