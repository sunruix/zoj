#include <stdio.h>
#include <math.h>

int main() {
    int n, m, i, j, k, a[1024], b[1024], *curp, *maxp, curn, maxn, *p;

    scanf("%d", &n);
    curp = a;
    maxp = b;
    curn = maxn = 0;
    for (m = n, k = sqrt(n), i = 2; i <= k; ++i) {
        if (0 == m % i) {
            for (curn = 0, j = i; !(m % j); ++j) {
                curp[curn++] = j;
                m /= j;
            }
            if (curn > maxn) {
                maxn = curn;
                p = curp;
                curp = maxp;
                maxp = p;
            }
            m = n;
        }
    }
    printf("%d\n", maxn ? maxn : 1);
    for (i = 0; i < maxn - 1; ++i)
        printf("%d*", maxp[i]);
    printf("%d\n", maxn ? maxp[i] : n);
    return 0;
}
