#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left, *right;
    int val;
};

struct node *new(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->left = n->right = NULL;
    n->val = x;
    return n;
}

struct node *build(int *in, int *post, int n) {
    int i;
    if (!n)
        return NULL;
    struct node *root = new(post[n - 1]);
    for (i = 0; in[i] != post[n - 1] && i < n; ++i);
    root->left = build(in, post, i);
    root->right = build(in + i + 1, post + i, n - i - 1);
    return root;
}

int main() {
    int n, i, j, k, in[128], post[128], head = 0, tail = 0, level = 1, ans[128];
    struct node *root, *q[128], *x;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &in[i]);
    for (i = 0; i < n; ++i)
        scanf("%d", &post[i]);
    root = build(in, post, n);
    q[tail++] = NULL;
    q[tail++] = root;
    k = 0;
    while (head != tail) {
        x = q[head++];
        if (!x) {
            if (level & 1) {
                for (i = tail - 1; i >= head; --i)
                    ans[k++] = q[i]->val;
            }
            else {
                for (i = head; i < tail; ++i)
                    ans[k++] = q[i]->val;
            }
            ++level;
            if (head == tail)
                break;
            else
                q[tail++] = NULL;
        }
        else {
            if (x->left)
                q[tail++] = x->left;
            if (x->right)
                q[tail++] = x->right;
        }
    }
    for (i = 0; i < n - 1; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
    return 0;
}

