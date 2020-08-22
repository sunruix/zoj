#include <stdio.h>
#include <string.h>

#define MAXLEN 128

int main()
{
    int a[10] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
    int head, tail, i, ans, carry, n[MAXLEN << 1];
    char s[MAXLEN << 1];
    freopen("input", "r", stdin);
    while (scanf("%s", s + MAXLEN) != EOF) {
        head = MAXLEN;
        for (i = head; s[i] != '\0'; ++i)
            n[i] = s[i] - '0';
        tail = i - 1;
        ans = 1;
        while (head != tail) {
            ans *= a[n[tail]];
            int x = (n[tail - 1] + (tail - 2 < head ? 0 : 10 * n[tail - 2])) << 1;
            x = x & 3 ? (x & 3) : 4;
            x = (1 << x) % 10;
            ans = (ans * x) % 10;
            for (i = tail--, carry = 0; i >= head; --i) {
                n[i] = (n[i] << 1) + carry;
                if (n[i] >= 10) {
                    carry = 1;
                    n[i] -= 10;
                }
                else {
                    carry = 0;
                }
            }
            if (carry)
                n[--head] = 1;
        }
        ans *= a[n[tail]];
        printf("%d\n", ans % 10);
    }
    return 0;
}