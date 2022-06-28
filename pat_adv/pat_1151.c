#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int key, pos;
} cell;

int cmp(const void *a, const void *b) {
    return ((cell *)a)->key - ((cell *)b)->key;
}

int main() {
    int n, m, i, j, k, in[10000], pre[10000], u, v;
    cell ppre[10000], pin[10000], cu, cv, cw, *pu, *pv, *pw, *p;
    freopen("input", "r", stdin);
    scanf("%d %d", &m, &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
        pin[i].key = in[i];
        pin[i].pos = i;
    }
    for (i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
        ppre[i].key = pre[i];
        ppre[i].pos = i;
    }
    qsort(pin, n, sizeof(cell), cmp);
    qsort(ppre, n, sizeof(cell), cmp);
    while (m--) {
        scanf("%d %d", &u, &v);
        cu.key = u;
        cv.key = v;
        pu = bsearch(&cu, pin, n, sizeof(cell), cmp);
        pv = bsearch(&cv, pin, n, sizeof(cell), cmp);
        if (!pu && !pv)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (!pu || !pv)
            printf("ERROR: %d is not found.\n", pu ? v : u);
        else {
            int l = min(pu->pos, pv->pos), r = max(pu->pos, pv->pos), min_pre = n;
            for (i = l; i <= r; ++i) {
                cw.key = in[i];
                pw = bsearch(&cw, ppre, n, sizeof(cell), cmp);
                if (min_pre > pw->pos) {
                    min_pre = pw->pos;
                    p = pw;
                }
            }
            if (p->key != u && p->key != v)
                printf("LCA of %d and %d is %d.\n", u, v, p->key);
            else
                printf("%d is an ancestor of %d.\n", p->key == u ? u : v, p->key == u ? v : u);
        }
    }
    return 0;
}
