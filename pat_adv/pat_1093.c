#include <stdio.h>

int main() {
    int i, j, k, ap[100001], at[100001], an, pn, tn;
    long long ans;
    char s[100001];
    freopen("input", "r", stdin);
    scanf("%s", s);
    an = pn = tn = 0;
    for (i = 0; s[i] != '\0'; ++i)
        if (s[i] == 'P')
            ++pn;
        else if (s[i] == 'A')
            ap[an++] = pn;
    k = an;
    for (j = i; j >= 0; --j)
        if (s[j] == 'T')
            ++tn;
        else if (s[j] == 'A')
            at[--k] = tn;
    for (ans = 0, i = 0; i < an; ++i)
        ans += ap[i] * at[i] % 1000000007;
    printf("%d\n", ans % 1000000007);
    return 0;
}
