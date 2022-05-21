#include <stdio.h>

int main() {
    int k, n, i, j, yes, col[1024];
    freopen("input", "r", stdin);
    scanf("%d", &k);
    while (k--) {
        yes = 1;
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            scanf("%d", &col[i]);
            for (j = 1; j < i && yes; ++j) {
                if (col[j] == col[i] || i - j == col[i] - col[j] || i - j == col[j] - col[i])
                    yes = 0;
            }
        }
        printf("%s\n", yes ? "YES" : "NO");
    }
    return 0;
}
