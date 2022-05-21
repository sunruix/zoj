#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int prime[10000] = {2}, last = 1;
int isprime(int n) {
    int i, k;
    for (k = sqrt(n), i = 0; prime[i] <= k && i < last; ++i)
        if (!(n % prime[i]))
            return 0;
    return prime[last++] = n;
}

int main() {
    int n, m, i, j, k, p, key, *table, probe, hash, mod;
    freopen("input", "r", stdin);
    scanf("%d %d", &m, &n);
    if (m == 1)
        m = 2;
    else if (m != 2)
        m = m + !(m & 1);
    for (i = 3; i <= m; isprime(i), i += 2);
    if (prime[last - 1] != m)
        for (i = m + 2; !isprime(i); ++i);
    p = prime[last - 1];
    table = malloc(p * sizeof(int));
    memset(table, 0, p * sizeof(int));
    for (i = 0; i < n; ++i) {
        scanf("%d", &key);
        for (mod = key % p, probe = 0; table[hash = (mod + probe * probe) % p] && probe < p; ++probe);
        if (probe < p) {
            table[hash] = key;
            printf("%d", hash);
        }
        else
            printf("-");
        printf("%s", i == n - 1 ? "\n" : " ");
    }
    return 0;
}
