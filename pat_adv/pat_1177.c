#include <stdio.h>

int main() {
    int i, j, k, min = 10001, left, right, l, r, pos[128][10002] = {0}, ps[128][2] = {0}, os[128] = {0};
    char s[10002], p[10002];
    freopen("input", "r", stdin);
    scanf("%s%s", s, p);
    for (i = 0; s[i] != '\0'; ++i)
        pos[s[i]][ps[s[i]][0]++] = i;
    for (k = 0; k < ps[p[0]][0]; ++k) {
        for (i = 'a'; i <= 'z'; os[i++] = 0);
        right = left = pos[p[0]][k];
        for (i = 1; p[i] != '\0'; ++i) {
            for (j = ps[p[i]][1] + os[p[i]]; j < ps[p[i]][0] && pos[p[i]][j] <= right; ++j);
            if (j < ps[p[i]][0]) {
                if (os[p[i]] == 0) {
                    ps[p[i]][1] = j;
                    os[p[i]] = 1;
                }
                else
                    ++os[p[i]];
                right = pos[p[i]][j];
            }
            else {
                right = -1;
                break;
            }
        }
        if (right == -1)
            break;
        else if (min > right - left) {
            min = right - left;
            l = left;
            r = right;
        }
    }
    s[r + 1] = '\0';
    printf("%s\n", s + l);
    return 0;
}
