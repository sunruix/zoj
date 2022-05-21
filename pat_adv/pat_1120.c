#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, i, j, k, m = 0, ans[10000], map[10000] = {0};
    char s[8];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        for (k = 0, i = 0; s[i] != '\0'; ++i)
            k += s[i] - '0';
        if (!map[k]) {
            map[k] = 1;
            ans[m++] = k;
        }
    }
    qsort(ans, m, sizeof(int), cmp);
    printf("%d\n", m);
    for (i = 0; i < m - 1; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
    return 0;
}
