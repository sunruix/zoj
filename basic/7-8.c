#include <stdio.h>

int main() {
    int a;
    while (scanf("%d", &a) != EOF)
        printf("Speed: %d - %s\n", a, a <= 60 ? "OK" : "Speeding");
    return 0;
}
