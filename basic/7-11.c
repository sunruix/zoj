#include <stdio.h>

int main() {
    float t;
    while (scanf("%f", &t) != EOF)
        printf("%.2f\n", t > 15 ? 2.5 * t - 17.5 : 4 * t / 3);
    return 0;
}
