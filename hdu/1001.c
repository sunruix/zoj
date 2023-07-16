#include <stdio.h>

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        if (n & 1)
            m = n + 1 >> 1;
        else {
            m = n >> 1;
            ++n;
        }
        printf("%d\n\n", m * n);
    }
    return 0;
}
