#include <stdio.h>
#include <math.h>

int prime[10000] = {2, 3, 5, 7}, psize = 4;
int isprime(int x) {
    if (!(x % 2) || !(x % 3) || !(x % 5) || !(x % 7))
        return 0;
    int i, y = sqrt(x);
    for (i = 0; i < psize && prime[i] <= y; ++i) {
        if (!(x % prime[i]))
            return 0;
    }
    return prime[psize++] = x;
}

int main() {
    int msize, n, m, i, j, k, x, mod, probe, table[20000] = {0}, hash, count = 0;
    freopen("input", "r", stdin);
    scanf("%d %d %d", &msize, &n, &m);
    for (i = 0; i < psize && prime[i] < msize; ++i);
    if (i == psize) {
        for (i = prime[psize - 1] + 2; !isprime(i) || i < msize; i += 2);
        msize = i;
    }
    else
        msize = prime[i];
    probe = 1 + (msize >> 1);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        for (j = 0, mod = x % msize; j < probe && table[hash = (mod + j * j) % msize]; ++j);
        if (j == probe)
            printf("%d cannot be inserted.\n", x);
        else
            table[hash] = x;
    }
    probe = 1 + msize;
    for (i = 0; i < m; ++i) {
        scanf("%d", &x);
        for (j = 0, mod = x % msize; j < probe && table[hash = (mod + j * j) % msize] && table[hash] != x; ++j);
        count += j + (j < probe);
    }
    printf("%.1f\n", (double)count / m);
    return 0;
}
