#include <stdio.h>

int main() {
    int n, m, i, j, w, a[10001], sum, ans = 0;
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    scanf("%d", &a[0]);
    sum = a[0];
    i = j = 0;
    while (j < n) {
        if (sum <= m && i < n) {
            scanf("%d", &a[++i]);
            sum += a[i];
        }
        else {
            ans += i - j;
            sum -= a[j++];
        }
    }
    printf("%d\n", ans);
    return 0;
}
