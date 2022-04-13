#include <stdio.h>

int main() {
    int n, i, ans;
    long long a, b, c;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if ((a >= 0 && b <= 0) || (a <= 0 && b >= 0))
            ans = a + b > c;
        else if (b >= 0 && c <= 0)
            ans = 1;
        else if (b <= 0 && c >= 0)
            ans = 0;
        else
            ans = a > c - b;
        printf("Case #%d: %s\n", i, ans ? "true" : "false");
    }
    return 0;
}
