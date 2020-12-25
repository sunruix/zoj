#include <stdio.h>

int main()
{
    unsigned int i, j, k, p, q = 34943, r;
    char s[2048], ans[8];

    while (fgets(s, sizeof(s), stdin) && s[0] != '#') {
        p = i = j = 0;
        while (s[i] != '\n') {
            for (; p < q && j < 8; s[i] <<= 1, ++j)
                p = ((p << 1) + ((s[i] & 0x80) >> 7));
            p < q ? (++i, j = 0) : (p -= q);
        }
        sprintf(ans, "%.4X", p ? q - (p << 16) % q : 0);
        printf("%c%c %c%c\n", ans[0], ans[1], ans[2], ans[3]);
    }
    return 0;
}
