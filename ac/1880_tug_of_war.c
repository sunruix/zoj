#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define MAX_N 128
#define MAX_W 512

int a[MAX_N];
char dp[2][MAX_N][MAX_N * MAX_W];

int main()
{
    int n, i, j, k, d, dw1, dw2, w, sum;
    int z1 = MAX_N >> 1, z2 = MAX_N * MAX_W >> 1;
    freopen("input", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        dp[1][z1][z2] = 1;
        for (sum = 0, i = 1, j = 0; i <= n; ++i, j = !j) {
            scanf("%d", &a[i]);
            for (w = (sum += a[i]); w >= -sum; --w)
                for (d = min(i, (n - i) + 1); d >= -min(i, (n - i) + 1); --d) {
                    dp[j][z1 + d][z2 + w] = dp[!j][z1 + d - 1][z2 + w - a[i]] || dp[!j][z1 + d + 1][z2 + w + a[i]];
                }
            memset(dp[!j], 0, sizeof(dp[!j]));
        }
        j = !(n & 1);
        for (k = sum, w = -sum; w <= sum; ++w) {
            if (dp[j][z1 + !j][w + z2] && k > (w > 0 ? w : -w))
                k = w > 0 ? w : -w;
        }
        printf("%d %d\n", (sum - k) >> 1, (sum + k) >> 1);
    }
    return 0;
}