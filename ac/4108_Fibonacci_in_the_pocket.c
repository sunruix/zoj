#include <stdio.h>

int main()
{
    int n, a, b, i;
    char s1[100000], s2[100000];
    scanf("%d", &n);
    while (n--) {
        scanf("%s %s", s1, s2);
        a = b = 0;
        for (i = 0; s1[i] != '\0'; a += s1[i++] - '0');
        for (i = 0; s2[i] != '\0'; b += s2[i++] - '0');
        a %= 3;
        b %= 3;
        a = (b + 3 - a + 1) % 3;
        printf("%d\n", (a == 1 && b) || (a == 2 && b != 2) ? 1 : 0);
    }
    return 0;
}
