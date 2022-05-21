#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dot 64

int sum[128], t[128];
char s[128];

void add() {
    int i, carry = 0;
    for (i = 127; i >= 0; --i) {
        sum[i] += t[i] + carry;
        if (sum[i] >= 10) {
            sum[i] -= 10;
            carry = 1;
        }
        else
            carry = 0;
    }
}

int main() {
    long long n;
    int i, j, k, d;
    double a;
    freopen("input", "r", stdin);
    memset(sum, 0, sizeof(sum));
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%lf", &a);
        a *= (n - i) * (i + 1);
        sprintf(s, "%.16f", a);
        for (d = 0; s[d] != '.'; ++d);
        memset(t, 0, sizeof(t));
        for (j = d + 1, k = dot; s[j] != '\0'; t[k++] = s[j++] - '0');
        for (j = d - 1, k = dot - 1; j >= 0; t[k--] = s[j--] - '0');
        add();
    }
    if (sum[dot + 2] >= 5) {
        memset(t, 0, sizeof(t));
        t[dot + 1] = 1;
        add();
    }
        
    for (i = 0; sum[i] == 0 && i < dot; ++i);
    i = i < dot ? i : dot - 1;
    for ( ; i < dot; ++i)
        printf("%d", sum[i]);
    printf(".%d%d\n", sum[dot], sum[dot + 1]);
    return 0;
}
