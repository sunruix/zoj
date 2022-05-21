#include <stdio.h>
#include <string.h>

int main() {
    char digits[16][8] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char units[16][8] = {"Yi", "Qian", "Bai", "Shi", "Wan", "Qian", "Bai", "Shi", "Ge"};
    char s[16], ans[32][8];
    int i, j, k, len, wan_triger = 0;
    freopen("input", "r", stdin);
    while (scanf("%s", s) != EOF) {
        memset(ans, 0, sizeof(ans));
        wan_triger = 0;
        if (s[k = 0] == '-') {
            strcpy(ans[k++], "Fu");
            len = strlen(s + 1);
            i = 1;
        }
        else {
            len = strlen(s);
            i = 0;
        }
        j = 9 - len;
        while (s[i] != '\0') {
            if (s[i] != '0') {
                strcpy(ans[k++], digits[s[i] - '0']);
                strcpy(ans[k++], units[j]);
                if (j >= 1 && j <= 3)
                    wan_triger = 1;
                ++i;
                ++j;
            }
            else {
                while (s[i] == '0') {
                    if (!strcmp(units[j], "Wan") && wan_triger)
                        strcpy(ans[k++], "Wan");
                    ++i;
                    ++j;
                }
                strcpy(ans[k++], "ling");
            }
        }
        if (!strcmp(ans[k - 1], "Ge"))
            --k;
        if (!strcmp(ans[k - 1], "ling"))
            --k;
        for (i = 0; i < k - 1; ++i)
            printf("%s ", ans[i]);
        printf("%s\n", ans[i]);
    }
    return 0;
}

