#include <stdio.h>
#include <string.h>

int convert(char *s, char *t, int sig) {
    int i, j, p, q;
    
    for (i = 0; s[i] != '\0' && !(s[i] >= '1' && s[i] <= '9'); ++i);
    q = i;
    for (j = 0; j < sig && s[i] != '\0'; ++i)
        if (s[i] != '.')
            t[j++] = s[i];
    for ( ; j < sig; ++j)
        t[j] = '0';
    t[j] = '\0';
    for (i = 0; s[i] != '\0' && s[i] != '.'; ++i);
    p = i;
    if (q == strlen(s))
        return 0;
    return p < q ? p - q + 1 : p - q;
}

int main()
{
    int n, ca, cb;
    char a[128], b[128], na[128], nb[128];
    freopen("input", "r", stdin);
    while (scanf("%d %s %s", &n, a, b) != EOF) {
        ca = convert(a, na, n);
        cb = convert(b, nb, n);
        if (ca == cb && !strcmp(na, nb))
            printf("YES %s%s%s%d\n", "0.", na, "*10^", ca);
        else
            printf("NO %s%s%s%d %s%s%s%d\n", "0.", na, "*10^", ca, "0.", nb, "*10^", cb);
    }
    return 0;
}
