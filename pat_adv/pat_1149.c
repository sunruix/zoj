#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int a, b;
} pair;

int cmp(const void *a, const void *b) {
    pair *pa = (pair *)a, *pb = (pair *)b;
    if (pa->a == pb->a)
        return pa->b - pb->b;
    return pa->a - pb->a;
}

int main() {
    int n, m, i, j, k, a, b, g[100000] = {0}, l[1024];
    pair incmp[10000], temp;
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        g[a] = g[b] = 1;
        incmp[i].a = min(a, b);
        incmp[i].b = max(a, b);
    }
    qsort(incmp, n, sizeof(pair), cmp);
    while (m--) {
        scanf("%d", &k);
        for (i = 0; i < k; ++i)
            scanf("%d", &l[i]);
        int no = 0;
        for (i = 0; i < k - 1 && !no; ++i) {
            for (j = i + 1; j < k && g[l[i]] && !no; ++j) {
                if (g[l[j]]) {
                    temp.a = min(l[i], l[j]);
                    temp.b = max(l[i], l[j]);
                    no = bsearch(&temp, incmp, n, sizeof(pair), cmp) != NULL;
                }
            }
        }
        printf("%s\n", no ? "No" : "Yes");
    }
    return 0;
}
