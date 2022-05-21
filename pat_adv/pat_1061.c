#include <stdio.h>
#include <ctype.h>

int main() {
    int i, j, k, w, h, m;
    char s1[64], s2[64], s3[64], s4[64];
    char *week[8] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    freopen("input", "r", stdin);
    while (scanf("%s %s %s %s", s1, s2, s3, s4) != EOF) {
        for (i = 0; s1[i] != '\0' && !(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G'); ++i);
        w = s1[k = i] - 'A';
        for (++i; !(s1[i] == s2[i] && (isdigit(s1[i]) || s1[i] >= 'A' && s1[i] <= 'N')); ++i);
        h = isdigit(s1[i]) ? s1[i] - '0' : (s1[i] - 'A' + 10);
        for (i = 0; s3[i] != '\0' && (s3[i] != s4[i] || !isalpha(s3[i])); ++i);
        m = i;
        printf("%s %0.2d:%0.2d\n", week[w], h, m);
    }
    return 0;
}

