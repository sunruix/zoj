#include <stdio.h>

int main()
{
    int n, i, k1, k2, x, y, a[200000][2];
    freopen("input", "r", stdin);
    while (scanf("%d", &n) != EOF && n) {
        for (i = 0; i < n; ++i)
            scanf("%d %d", &a[i][0], &a[i][1]);
        for (x = a[n >> 1][0], y = a[n >> 1][1], k1 = k2 = i = 0; i < n; ++i) {
            if ((a[i][0] > x && a[i][1] > y) || (a[i][0] < x && a[i][1] < y))
                ++k1;
            else if ((a[i][0] > x && a[i][1] < y) || (a[i][0] < x && a[i][1] > y))
                ++k2;
        }
        printf("%d %d\n", k1, k2);
    }
    return 0;
}