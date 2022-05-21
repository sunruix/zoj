#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, i, j, k, exp;
    char s[32768] = {0};
    scanf("%s", s);
    if (s[0] == '-')
        printf("-");
    for (i = 3; s[i] != 'E'; ++i);
    exp = atoi(s + i + 1);
    while (s[i] != '\0')
        s[i++] = '\0';
    if (!exp)
        printf("%s\n", s + 2);
    else if (exp < 0) {
        printf("0.");
        for (i = 0; i > exp + 1; --i)
            printf("0");
        printf("%c%s\n", s[1], s + 3);
    }
    else {
        for (i = 0; i < exp; ++i)
            s[2 + i] = s[2 + i + 1];
        s[2 + i] = '.';
        for (i = 1; s[i] != '.'; ++i)
            printf("%c", s[i] == '\0' ? '0' : s[i]);
        printf("%s\n", s[i + 1] == '\0' ? "" : s + i);
    }
    return 0;
}
