#include <stdio.h>

int main() {
    int n, d, u, h, i;
    while (scanf("%d %d %d", &n, &u, &d) != EOF) {
        for (h = 0, i = 0; h < n; ++i)
            h += (i & 1) ? -d : u;
        printf("%d\n", i);
    }
    return 0;
}
