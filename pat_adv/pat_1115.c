#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

typedef struct node *bst;

bst new(int x) {
    bst new = malloc(sizeof(struct node));
    new->key = x;
    new->left = new->right = NULL;
    return new;
}

bst insert(bst t, int x) {
    struct node *p = t, *q = NULL, *r = new(x);
    if (!t)
        return r;
    while (1) {
        if (x <= p->key) {
            if (!p->left) {
                p->left = r;
                break;
            }
            else
                p = p->left;
        }
        else {
            if (!p->right) {
                p->right = r;
                break;
            }
            else
                p = p->right;
        }
    }
    return t;
}

int main() {
    int n, i, j, k, x, head = 0, tail = 0, ans[2];
    bst root = NULL, front, q[2048];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    q[tail++] = root;
    q[tail++] = NULL;
    ans[k = 0] = 1;
    while (head != tail) {
        front = q[head++];
        if (!front) {
            if (head == tail)
                break;
            ans[k = !k] = tail - head;
            q[tail++] = NULL;
        }
        else {
            if (front->left)
                q[tail++] = front->left;
            if (front->right)
                q[tail++] = front->right;
        }
    }
    printf("%d + %d = %d\n", ans[k], ans[!k], ans[0] + ans[1]);
    return 0;
}

