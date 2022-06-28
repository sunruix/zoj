#include <stdio.h>
#include <math.h>

int isprime(int x) {
    if (x == 2 || x == 3 || x == 5 || x == 7)
        return 1;
    if (!(x % 2) || !(x % 3) || !(x % 5) || !(x % 7))
        return 0;
    int y = sqrt(x), i;
    for (i = 3; i <= y; i += 2)
        if (!(x % i))
            return 0;
    return 1;
}

int main() {
    int l, k, a, i, j;
    char s[1024], c;
    freopen("input", "r", stdin);
    scanf("%d %d %s", &l, &k, s);
    for (i = 0, j = k; j <= l; ++i, ++j) {
        c = s[j];
        s[j] = '\0';
        sscanf(s + i, "%d", &a);
        if (isprime(a)) {
            printf("%s\n", s + i);
            break;
        }
        s[j] = c;
    }
    if (j > l)
        printf("404\n");
    return 0;
}
