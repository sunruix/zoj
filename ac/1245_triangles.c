#include <stdio.h>
#include <string.h>

#define MAXLEN 256

int n, m, i, j, k, ans, x, t = 1;
char g[MAXLEN][MAXLEN];

int scan(int i, int j, int k)
{
    int ii, jj;
    ii = ((!(i & 1) && !(j & 1)) || ((i & 1) && (j & 1))) ? i - k + 1 : i + k - 1;
    if (ii >= 0 && ii < n) {
        for (jj = j - (k - 1); jj >= 0 && jj < j + k && jj < m - ii && g[ii][jj] == '-'; ++jj);
        if (jj == j + k)
            return 1;
    }
    return 0;
}
int main()
{
    while (scanf("%d\n", &n) != EOF && n) {
        memset(g, 0, sizeof(g));
        for (i = 0; i < n; ++i)
            fgets(g[i], MAXLEN, stdin);
        ans = 0;
        for (m = (n << 1) - 1, i = 0; i < n; ++i) {
            for (j = i; j < m - i; ++j) {
                if (g[i][j] == '-') {
                    for (k = 2; k <= n && scan(i, j, k); ++k);
                    if (ans < k - 1)
                        ans = k - 1;
                }
            }
        }
        printf("Triangle #%d\nThe largest triangle area is %d.\n\n", t++, ans * ans);
    }
    return 0;
}