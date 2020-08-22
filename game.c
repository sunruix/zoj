#include <stdio.h>

int main()
{
    int n, i, j, k;
    long long a[256] = {1, 0, 1};
    for (i = 4; i <= 200; i += 2)
        for (j = 2; j <= i; j += 2)
            a[i] += a[j - 2] * a[i - j];
    while (scanf("%d", &n) != EOF)
        printf("%lld\n", a[n << 1]);
    return 0;
}