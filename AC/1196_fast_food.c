#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned a[256], dp[32][256][256];
int n, m;

void init()
{
    int i, j, k, p;
    unsigned sum;
    for (i = 0; i < n; ++i) {
        for (j = i; j < n; ++j) {
            for (p = i; p <= j; ++p) {
                sum = 0;
                for (k = i; k <= j; ++k)
                    sum += p > k ? a[p] - a[k] : a[k] - a[p];
                if (dp[1][i][j] > sum)
                    dp[1][i][j] = sum;
            }
        }
    }
    for (k = 2; k <= m; ++k) {
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                if (k >= j - i + 1)
                    dp[k][i][j] = 0;
            }
        }
    }
}

int main()
{
    int i, j, k, l, d, count = 1;
    unsigned temp;
    freopen("input", "r", stdin);
    while (scanf("%d %d", &n, &m) != EOF && n && m) {
        memset(dp, -1, sizeof(dp));
        for (i = 0; i < n; ++i)
            scanf("%u", &a[i]);
        init();
        for (k = 2; k <= m; ++k) {
            for (i = 0; i < n; ++i) {
                for (j = i + 1; j < n; ++j) {
                    for (d = i; d < j; ++d) {
                        temp = dp[1][i][d] + dp[k - 1][d + 1][j];
                        if (temp < dp[k][i][j])
                            dp[k][i][j] = temp;
                    }
                }
            }
        }
        printf("Chain %d\nTotal distance sum = %u\n\n", count++, dp[m][0][n - 1]);
    }
    return 0;
}