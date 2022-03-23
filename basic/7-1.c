#include <stdio.h>

int main() {
    int cm, inch;
    while (scanf("%d", &cm) != EOF) {
        inch = cm  * 12 / 30.48;
        printf("%d %d\n", inch / 12, inch % 12);
    }
    return 0;
}
