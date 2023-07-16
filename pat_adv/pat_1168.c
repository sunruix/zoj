#include <stdio.h>
#include <math.h>

int isprime(int x) {
    if (x == 1)
        return 0;
    if (x == 2 || x == 3 || x == 5 || x == 7)
        return 1;
    if (!(x % 2 && x % 3 && x % 5 && x % 7))
        return 0;
    int y = sqrt(x), i;
    for (i = 9; i <= y; ++i)
        if (0 == x % i)
            return 0;
    return 1;
}

int main() {
    freopen("input", "r", stdin);
    char day[16];
    int d, p, all = 1, i;
    scanf("%s", day);
    for (i = 0; i < 8; ++i) {
        sscanf(day + i, "%d", &d);
        p = isprime(d);
        all = all && p;
        printf("%s %s\n", day + i, p ? "Yes" : "No");
    }
    if (all)
        printf("All Prime!\n");
    return 0;
}
