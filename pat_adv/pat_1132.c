#include <stdio.h>
#include <string.h>

int main() {
    char s[16];
    int a, b, c, l, n, i;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        sscanf(s, "%d", &c);
        l = strlen(s);
        for (i = l; i > (l >> 1); --i)
            s[i] = s[i - 1];
        s[i] = s[l + 1] = '\0';
        sscanf(s, "%d", &a);
        sscanf(s + (l >> 1) + 1, "%d", &b);
        printf("%s\n", !(a * b) || c % (a * b) ? "No" : "Yes");
    }
    return 0;
}
