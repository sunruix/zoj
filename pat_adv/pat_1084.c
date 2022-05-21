#include <stdio.h>
#include <ctype.h>

char ascii[256];

int main()
{
    int i, j, k;
    char s1[128], s2[128], ans[128], c;

    scanf("%s %s", s1, s2);
    for (i = 0; s2[i] != '\0'; ++i)
        ascii[toupper(s2[i])] = 1;
    for (k = i = 0; s1[i] != '\0'; ++i) {
        c = toupper(s1[i]);
        if (!ascii[c]) {
            ans[k++] = c;
            ascii[c] = 1;
        }
    }
    for (i = 0; i < k; ++i)
        printf("%c", ans[i]);
    printf("\n");
    return 0;
}
