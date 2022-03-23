#include <stdio.h>

int main() {
    int a;
    while (scanf("%d", &a) != EOF)
        printf("%d\n", (a / 16) * 10 + a % 16);
    return 0;
}
