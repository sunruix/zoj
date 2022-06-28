#include <stdio.h>
#include <math.h>

int isprime(int x) {
    if (x <= 1)
        return 0;
    if (x == 2 || x == 5 || x == 7 || x == 3)
        return 1;
    if (!(x % 2) || !(x % 3) || !(x % 5) || !(x % 7))
        return 0;
    int y = sqrt(x), i;
    for (i = 9; i <= y; i += 2)
        if (!(x % i))
            return 0;
    return 1;
}

int main() {
    int n, m, i, j, k, six[3];
    scanf("%d", &n);
    six[0] = isprime(n - 6);
    six[1] = isprime(n);
    six[2] = isprime(n + 6);
    if (six[1] && (six[0] || six[2]))
        printf("Yes\n%d\n", six[0] ? n - 6 : n + 6);
    else {
        for (i = n + (n & 1 ? 2 : 1); !isprime(i) || !isprime(i - 6); i += 2);
        printf("No\n%d\n", n < i - 6 ? i - 6 : i);
    }
    return 0;
}
