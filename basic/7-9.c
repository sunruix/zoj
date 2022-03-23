#include <stdio.h>

int main() {
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) != EOF)
        printf("%C\n", a == b ? 'C' : (a == c ? 'B' : 'A'));
    return 0;
}
