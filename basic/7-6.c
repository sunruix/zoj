#include <stdio.h>

int main() {
    char c;
    int a;
    float f1, f2;
    while (scanf("%f %d %c %f", &f1, &a, &c, &f2) != EOF)
        printf("%c %d %.2f %.2f\n", c, a, f1, f2);

    return 0;
}
