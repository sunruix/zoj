#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int val, x, y;
} cell;

int N, sqr, i, j, k, m, n, b[10000][10000], idx;
cell a[10000];

int cmp(const void *a, const void *b) {
    return ((cell *)b)->val - ((cell *)a)->val;
}

void proc(int x0, int y0, int x1, int y1) {
    int i = x0, j = y0, k = y1 - y0 > 1 ? (x1 - x0 + y1  - y0 << 1) - 4 : (x1 - x0);
    while (k-- > 0) {
        a[idx].x = i;
        a[idx++].y = j;
        if (i == x0 && j < y1 - 1)
            ++j;
        else if (i < x1 - 1 && j == y1 - 1)
            ++i;
        else if (i == x1 - 1 && j > y0)
            --j;
        else
            --i;
    }
}

int main() {
    freopen("input", "r", stdin);
    scanf("%d", &N);
    for (i = 0; i < N; ++i)
        scanf("%d", &a[i].val);
    qsort(a, N, sizeof(cell), cmp);
    for (i = 1, sqr = sqrt(N); i <= sqr; ++i) {
        if (!(N % i)) {
            n = i;
            m = N / n;
        }
    }
    for (i = 0, j = 0, k = 0; k <= (n >> 1); ++k)
        proc(i + k, j + k, m - k, n - k);
    for (i = 0; i < N; ++i)
        b[a[i].x][a[i].y] = a[i].val;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n - 1; ++j)
            printf("%d ", b[i][j]);
        printf("%d\n", b[i][j]);
    }
    return 0;
}
