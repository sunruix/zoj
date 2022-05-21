#include <stdio.h>

int check(int *map, int n, int k) {
    int i, j;
    if (n % k)
        return 0;
    for (i = 1; i < n && map[i + k - 1] - map[i] == k - 1; i += k);
    return i > n;
}

int main() {
    int k, i, j, map[256][1024] = {0};
    char s[1024] = {0}, t[1024] = {0};
    freopen("input", "r", stdin);
    scanf("%d\n%s", &k, s);
    for (i = 0; s[i] != '\0'; ++i)
        map[s[i]][++map[s[i]][0]] = i;
    for (i = 0, j = 0; s[i] != '\0'; ++j) {
        t[j] = s[i];
        if (map[s[i]][0] < 0)
            i += k;
        else if (check(map[s[i]], map[s[i]][0], k)) {
            putchar(s[i]);
            map[s[i]][0] = -1;
            i += k;
        }
        else
            ++i;
    }
    printf("\n%s\n", t);
    return 0;
}
