#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int item;
    struct node *left, *right;
} *stack[32];

int ans[32], p;

void traversal(struct node *t) {
    if (t) {
        traversal(t->left);
        traversal(t->right);
        ans[p++] = t->item;
    }
}

int main() {
    int n, i, j, x, top = -1;
    char op[64][8] = {0};
    struct node *t, *pop = NULL, *root;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < (n << 1); ++i) {
        scanf("%s", op[i]);
        if (!strcmp(op[i], "Push")) {
            scanf("%d", &x);
            t = malloc(sizeof(struct node));
            t->item = x;
            t->left = t->right = NULL;
            if (i > 0)
                strcmp(op[i - 1], "Push") ? (pop->right = t) : (stack[top]->left = t);
            else
                root = t;
            stack[++top] = t;
        }
        else
            pop = stack[top--];
    }
    traversal(root);
    for (i = 0; i < n - 1; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
    return 0;
}
