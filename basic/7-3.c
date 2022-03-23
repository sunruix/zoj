#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[4], c;
    while (scanf("%s", s) != EOF) {
        c = s[0], s[0] = s[2], s[2] = c;
        printf("%d\n", atoi(s));
    }
    return 0;
}
