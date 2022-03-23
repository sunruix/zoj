#include <stdio.h>

int main() {
    int y, h;
    while (scanf("%d %d", &y, &h) != EOF)
        printf("%.2f\n", (y < 5 ? 30 : 50) * (h > 40 ? (h - 40) * 1.5 + 40 : h));
    return 0;
}
