#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, a[100000], s[100000], ans = 0, scount = 0;
    freopen("input", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        memset(s, -1, sizeof(s));
        ans = scount = 0;
        for (i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (i = 0; i < n; ++i) {
            if (a[i] != i && s[i] == -1) {
                ++scount;
                j = i;
                while (a[j] != j && s[j] == -1) {
                    ++ans;
                    s[j] = 1;
                    j = a[j];
                }
            }
        }
        if (ans && a[0] != 0) {
                --scount;
                --ans;
        }
        printf("%d\n", ans + scount);
    }
    return 0;
}
