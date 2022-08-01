#include <stdio.h>

#define mod  1000000007

int main() {
    int i, m[100000] = {1, 1};
    char s[100000];
    freopen("input", "r", stdin);
    scanf("%s", s + 1);
    for (i = 2; s[i] != '\0'; ++i) {
        if (s[i - 1] == '0')
            m[i] = m[i - 2] % mod;
        else {
            m[i] = m[i - 1] % mod;
            if ((s[i - 1] - '0') * 10 + s[i] - '0' < 26)
                m[i] = (m[i] + m[i - 2] % mod) % mod;
        }
    }
    printf("%d\n", m[i - 1]);
    return 0;
}

