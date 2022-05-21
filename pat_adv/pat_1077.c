#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, k, l1, l2, len = 0x7FFFFFFF;
    char s1[512], s2[512];
    freopen("input", "r", stdin);
    scanf("%d\n", &n);
    fgets(s1, sizeof(s1), stdin);
    l1 = strlen(s1);
    for (i = 1; i < n; ++i) {
        fgets(s2, sizeof(s2), stdin);
        l2 = strlen(s2);
        for (j = l1, k = l2; j >= 0 && k >= 0 && s1[j] == s2[k]; --j, --k);
        if (len > l1 - j - 1)
            len = l1 - j - 1;
    }
    printf("%s", len > 1 ? s1 + l1 - len : "nai\n");
    return 0;
}
