#include <stdio.h>

int main() {
    long long n, i;
    long double a, ans = 0;
    scanf("%lld", &n);
    for (i = 0; i < n; ++i) {
        scanf("%Lf", &a);
        ans += a * (i + 1) * (n - i);
    }
    printf("%.2Lf\n", ans);
    return 0;
}
