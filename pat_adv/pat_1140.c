#include <stdio.h>

int main() {
    int d, n, i, j, k, s[2][1 << 17] = {0}, p, len[2];
    freopen("input", "r", stdin);
    scanf("%d %d", &d, &n);
    s[n & 1][0] = d;
    len[n & 1] = 1;
    while (--n) {
        p = !(n & 1);
        len[!p] = 0;
        for (i = 0; i < len[p]; i += k) {
            for (k = 0; s[p][i + k] == s[p][i] && i + k < len[p]; ++k);
            s[!p][len[!p]++] = s[p][i];
            int temp[16];
            for (j = 0; k >= 10; k /= 10, ++j)
                temp[j] = k % 10;
            temp[j++] = k;
            while (j--)
                s[!p][len[!p]++] = temp[j];
        }
    }
    for (i = 0; i < len[n + 1 & 1]; ++i)
        printf("%d", s[n + 1 & 1][i]);
    printf("\n");
    return 0;
}
