#include <stdio.h>
#include <ctype.h>

int main() {
    int n, i, j, k, l;
    char map[32][8][8], word[16], c;
    freopen("input", "r", stdin);
    for (i = 0; i < 26; ++i)
        for (j = 0; j < 7; ++j)
            scanf("%s\n", map[i][j]);
    l = n = 0;
    while ((c = getchar()) != EOF) {
        if (isupper(c))
            word[n++] = c;
        else if (n) {
            if (l++)
                printf("\n");
            for (i = 0; i < 7; ++i) {
                for (j = 0; j < n - 1; ++j)
                    printf("%s ", map[word[j] - 'A'][i]);
                printf("%s\n", map[word[j] - 'A'][i]);
            }
            n = 0;
        }
    }
    return 0;
}
