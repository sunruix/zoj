#include <stdio.h>

int main() {
    int n, fn = 1, fn1 = 1;

    scanf("%d", &n);
    while (n > fn) {
        fn += fn1;
        fn1 = fn - fn1;
    }
    printf("%d\n", fn - n < n - fn1 ? fn : fn1);
    return 0;
}
