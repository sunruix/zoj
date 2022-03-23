#include <stdio.h>

int main() {
    float a, b, pi, n;
    while (scanf("%f", &b) != EOF) {
        pi = a = n = 1.0;
        while (a > b) {
            a *= (n / (2 * n + 1));
            pi += a;
            n += 1;
        }
        printf("%.6f\n", pi * 2);
    }
    return 0;
}
