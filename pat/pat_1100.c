#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char d1[16][8] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char d2[16][8] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main() {
    int n, i, j, k;
    char buf[32], m1[8], m2[8];
    freopen("input", "r", stdin);
    scanf("%d\n", &n);
    while (n--) {
        fgets(buf, 16, stdin);
        if (isdigit(buf[0])) {
            k = atoi(buf);
            if (k < 13)
                printf("%s\n", d1[k]);
            else if (k % 13)
                printf("%s %s\n", d2[k / 13], d1[k % 13]);
            else
                printf("%s\n", d2[k / 13]);
        }
        else {
            if (strlen(buf) > 5) {
                sscanf(buf, "%s %s", m2, m1);
                for (i = 0; i < 13 && strcmp(d2[i], m2); ++i);
                for (j = 0; j < 13 && strcmp(d1[j], m1); ++j);
                k = i * 13 + j;
            }
            else {
                sscanf(buf, "%s", m1);
                for (k = 0; k < 13 && strcmp(d1[k], m1); ++k);
                if (k == 13) {
                    for (k = 0; k < 13 && strcmp(d2[k], m1); ++k);
                    k *= 13;
                }
            }
            printf("%d\n", k);
        }
    }
    return 0;
}
