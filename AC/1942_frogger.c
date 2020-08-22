#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define distanc2(x1, x2, y1, y2) ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))

int find(int s[], int x)
{
    while (s[x] != -1)
        x = s[x];
    return x;
}

void uni(int x1, int x2, int s[])
{
    int r1 = find(s, x1), r2 = find(s, x2);
    if (r1 != r2)
        s[r1] = r2;
}

typedef struct {
    int u, v, len;
} edge;

int cmp(const void *a, const void *b)
{
    return ((edge *)a)->len - ((edge *)b)->len;
}

int main()
{
    int n, v[256][2], s[256], i, j, k, t = 1;
    edge e[256 * 256];

    while (scanf("%d", &n) && n) {
        memset(s, -1, sizeof(s));
        for (k = i = 0; i < n; ++i) {
            scanf("%d %d", &v[i][0], &v[i][1]);
            for (j = 0; j < i; ++j) {
                e[k].u = i;
                e[k].v = j;
                e[k++].len = distanc2(v[i][0], v[j][0], v[i][1], v[j][1]);
            }
        }
        qsort(e, k, sizeof(edge), cmp);
        for (i = 0; find(s, 0) != find(s, 1); ++i)
            uni(e[i].u, e[i].v, s);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", t++, sqrt(e[i - 1].len));
    }
    return 0;
}