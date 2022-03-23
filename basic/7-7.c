#include <stdio.h>

int main() {
    int h, m;
    while (scanf("%d:%d", &h, &m) != EOF)
        printf("%d:%d %s\n", h > 12 ? h % 12 : h, m, h >= 12 ? "PM" : "AM");
    return 0;
}
