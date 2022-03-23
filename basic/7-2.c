#include <stdio.h>

int main() {
    int h, m, start, pass;
    while (scanf("%d %d", &start, &pass) != EOF) {
        m = start % 100 + pass;
        h = start >= 100 ? start / 100 : 0;
        h = (h + m / 60) % 24;
        m = m > 0 ? m % 60 : -((-m) % 60);
        if (m < 0) {
            m += 60;
            h = (h - 1) % 24;
        }
        printf("%d%.2d\n", h, m);
    }
    return 0;
}

