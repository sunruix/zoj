#include <stdio.h>

int main() {
    int n, i, l1, r1, l2, r2, pre[50000], in[50000];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &pre[i]);
    for (i = 0; i < n; ++i)
        scanf("%d", &in[i]);
    l1 = l2 = 0;
    r1 = r2 = n - 1;
    while (l1 != r1) {
        for (i = l2; in[i] != pre[l1]; ++i);
        if (i == l2)
            ++l2;
        else
            r2 = i - 1;
        ++l1;
        r1 = r2 - l2 + l1;
    }
    printf("%d\n", pre[r1]);
    return 0;
}
