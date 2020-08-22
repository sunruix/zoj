#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, k;
    char buf[1024][1024], s[32768];

    while (scanf("%d", &n) != EOF) {
        memset(s, 0, sizeof(s));
        for (i = 0; i < n; ++i)
            scanf("%s", buf[i]);
        for (k = 0, i = strlen(buf[0])- 1; i >= 0; --i) {
            for (j = n - 1; j >= 0; --j) {
                s[k++] = buf[j][i] == '\\' ? '\n' : (buf[j][i] == '_' ? ' ' : buf[j][i]);
            }
        }
        for (i = strlen(s) - 1; i >= 0 && s[i] == ' '; --i)
            s[i] = '\0';
        printf("%s\n\n", s);
    }
    return 0;
}