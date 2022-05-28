#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, pos;
} node;

int cmp(const void *a, const void *b) {
    return ((node *)a)->val - ((node *)b)->val;
}

int main() {
    int m, n, i, j, k;
    node in[10000], u, v, *pu, *pv, *p, *lca;
    freopen("input", "r", stdin);
    scanf("%d %d", &m, &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &in[i].val);
        in[i].pos = i;
    }
    qsort(in, n, sizeof(node), cmp);
    while (m--) {
        scanf("%d %d", &u.val, &v.val);
        pu = bsearch(&u, in, n, sizeof(in[0]), cmp);
        pv = bsearch(&v, in, n, sizeof(in[0]), cmp);
        if (!pu || !pv) {
            printf("ERROR: ");
            if (pu || pv)
                printf("%d is not found.\n", pu ? v : u);
            else
                printf("%d and %d are not found.\n", u, v);
        }
        else {
            if (pu->val > pv->val) {
                p = pu;
                pu = pv;
                pv = p;
            }
            for (k = n, p = pu; p <= pv; ++p)
                if (k > p->pos)
                    k = (lca = p)->pos;
            if (lca == pu || lca == pv)
                printf("%d is an ancestor of %d.\n", lca->val, (lca == pu ? pv : pu)->val);
            else
                printf("LCA of %d and %d is %d.\n", u.val, v.val, lca->val);
        }
    }
    return 0;
}
