#include <stdio.h>

int main() {
    int m, n, i, j, k, t, x, stack[1024], top, yes, max;
    freopen("input", "r", stdin);
    scanf("%d %d %d", &m, &n, &t);
    while (t--) {
        yes = 1;
        stack[top = 0] = max = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d", &x);
            if (!yes)
                continue;
            if (x == stack[top])
                --top;
            else if (x < stack[top])
                yes = 0;
            else {
                for (j = max + 1; j < x; ++j)
                    stack[++top] = j;
                if (top >= m)
                    yes = 0;
            }
            if (max < x)
                max = x;
        }
        printf("%s\n", yes ? "YES" : "NO");
    }
    return 0;
}
