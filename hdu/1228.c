#include <stdio.h>
#include <string.h>

int convert(char *s) {
    char num[16][8] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int x, y = -1, i, j;
    for (i = 0; s[i] != ' ' && s[i] != '\0'; ++i);
    if (s[i] == ' ') {
        for (j = 0; j < 10 && strcmp(num[j], s + i + 1); ++j);
        y = j;
        s[i] = '\0';
    }
    for (j = 0; j < 10 && strcmp(num[j], s); ++j);
    x = j;
    return y >= 0 ? x * 10 + y : x;
}

int main() {
    int a, b, i, j, k;
    char s[128], sa[32], sb[32];
    freopen("input", "r", stdin);
    while (fgets(s, sizeof(s), stdin)) {
        for (i = 0; s[i] != '+'; ++i);
        s[i - 1] = '\0';
        for (j = i; s[j] != '='; ++j);
        s[j - 1] = '\0';
        a = convert(s);
        b = convert(s + i + 2);
        if (!a && !b)
            break;
        printf("%d\n", a + b);
    }
    return 0;
}
