#include <stdio.h>
#include <string.h>

int check(char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i <= j)
        if (s[i++] != s[j--])
            return 0;
    return 1;
}

int main() {
    char a[1024], b[1024], c[1024];
    int n, i, j, k, l, carry;

    scanf("%s", a);
    if (check(a))
        printf("%s is a palindromic number.\n", a);
    else {
        n = 10;
        while (n--) {
            l = strlen(a);
            for (i = 0, j = l - 1, b[l] = '\0'; j >= 0; ++i, --j)
                b[i] = a[j];
            printf("%s + %s = ", a, b);
            for (carry = 0, i = l - 1; i >= 0; --i) {
                a[i] = a[i] + b[i] - ('0' << 1) + carry;
                if (a[i] > 9) {
                    a[i] -= 10;
                    carry = 1;
                }
                else
                    carry = 0;
                a[i] += '0';
            }
            if (carry) {
                for (i = l + 1; i > 0; --i)
                    a[i] = a[i - 1];
                a[0] = '1';
            }
            printf("%s\n", a);
            if (check(a)) {
                printf("%s is a palindromic number.\n", a);
                break;
            }
        }
        if (n < 0)
            printf("Not found in 10 iterations.\n");
    }
    return 0;
}
