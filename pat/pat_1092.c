#include <stdio.h>

int main() {
    int i, j, miss = 0;
    char s[1024], t[1024], map[256] = {0};
    freopen("input", "r", stdin);
    scanf("%s %s", s, t);
    for (i = 0; s[i] != '\0'; ++i)
        ++map[s[i]];
    for (j = 0; t[j] != '\0'; ++j)
        map[t[j]] ? (--map[t[j]]) : (++miss);
    if (miss)
        printf("No %d\n", miss);
    else
        printf("Yes %d\n", i - j);
    return 0;
}
