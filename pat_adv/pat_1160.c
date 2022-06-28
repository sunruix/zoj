#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    int r;
    while (r = a % b) {
        a = b;
        b = r;
    }
    return b;
}

int isprime(int x) {
    if (x == 2 || x == 3 || x == 5 || x == 7)
        return 1;
    if (!(x % 2) || !(x % 3) || !(x % 5) || !(x % 7))
        return 0;
    int y = sqrt(x), i;
    for (i = 9; i <= y; ++i)
        if (!(x % i))
            return 0;
    return 1;
}

void print(int pos, int len, int left, int *a, int n, int k) {
    int i, start = pos ? 0 : 1;
    if (left < 0)
        return;
    if (!left && pos == len && a[len - 1] != 9) {
        printf("%d ", n);
        for (i = 0; i < len; ++i) {
            printf("%d", a[i]);
        }
        for (i = 0; i < k - len; ++i)
            printf("9");
        printf("\n");
    }
    else if (pos == len)
        return;
    else if (pos < len)
        for (i = start; i < 10; ++i) {
            a[pos] = i;
            print(pos + 1, len, left - i, a, n, k);
        }
}

int main() {
    int t, m, n, k, i, j, g, solu, a[16];
    freopen("input", "r", stdin);
    scanf("%d", &t);
    for (i = 1; i <= t; ++i) {
        printf("Case %d\n", i);
        solu = 0;
        scanf("%d %d", &k, &m);
        for (j = k - 1; j >= 1; --j) {
            n = m + 1 - 9 * j;
            if (n - 1 <= (k - j) * 9 && (g = gcd(m, n)) > 2 && isprime(g)) {
                print(0, k - j, n - 1, a, n, k);
                solu = 1;
            }
        }
        if (!solu)
            printf("No Solution\n");
    }
    return 0;
}
