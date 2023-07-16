#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b));

typedef struct {
    int a, b;
} nb;

int comp(const void *a, const void *b) {
    nb *pa = (nb *)a, *pb = (nb *)b;
    if (pa->a == pb->a)
        return pa->b - pb->b;
    return pa->a - pb->a;
}

int main() {
    int i, j, k, N, R, K, M, map[512][512], x, count, max, yes;
    char sp[512] = {0};
    nb a[250000], b;

    scanf("%d %d %d", &N, &R, &K);
    for (i = 0; i < R; ++i) {
        scanf("%d %d", &a[i].a, &a[i].b);
        if (a[i].a > a[i].b)
            swap(a[i].a, a[i].b);
    }
    qsort(a, R, sizeof(nb), comp);
    scanf("%d", &M);
    while (M--) {
        max = count = 0;
        memset(sp, 0, sizeof(sp));
        memset(map, 0, sizeof(map));
        for (i = 1; i <= N; ++i) {
            scanf("%d", &x);
            if (max < x)
                max = x;
            if (!sp[x])
                count += (sp[x] = 1);
            map[x][++map[x][0]] = i;
        }
        if (count != K)
            printf("Error: Too %s species.\n", count > K ? "many" : "few");
        else {
            yes = 1;
            for (i = 0; i <= max && yes; ++i) {
                for (j = 1; j < map[i][0] && yes; ++j)
                    for (k = j + 1; k <= map[i][0] && yes; ++k) {
                        b.a = map[i][j];
                        b.b = map[i][k];
                        yes = bsearch(&b, a, R, sizeof(nb), comp) ? 0 : 1;
                    }
            }
            printf("%s\n", yes ? "Yes" : "No");
        }
    }
    return 0;
}
