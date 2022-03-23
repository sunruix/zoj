#include <stdio.h>

int main() {
    int a, b, i, sum;
    while (scanf("%d %d", &a, &b) != EOF) {
        for (sum = 0, i = a; i <= b; ++i) {
            printf("%5d%s", i, (i - a) % 5 == 4 ? "\n" : "");
            sum += i;
        }
        printf("%sSum = %d\n", (i - a) % 5 ? "\n" : "", sum);
    }
    return 0;
}
