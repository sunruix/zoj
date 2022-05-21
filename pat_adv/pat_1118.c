#include <stdio.h>

int s[20002];

int find(int x) {
    while (s[x]) {
        if (s[s[x]])
            s[x] = s[s[x]];
        else
            return s[x];
        x = s[x];
    }
    return x;
}

int un(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) {
        s[rx] = ry;
        return 1;
    }
    return 0;
}

int main() {
    int n, i, j, k, x, y, m = 0, uncount = 0;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 10001; i < 10001 + n; ++i) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            if (s[x] != 0)
                uncount += un(i, x);
            s[x] = i;
            if (m < x)
                m = x;
        }
    }
    printf("%d %d\n", n - uncount, m);
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &x, &y);
        printf("%s\n", find(x) == find(y) ? "Yes" : "No");
    }
    return 0;
}
