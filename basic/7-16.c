#include <stdio.h>

int main() {
    int a[4], i, j, k, l;
    while (scanf("%d", &a[0]) != EOF) {
        for (i = 1; i < 4; ++i)
            a[i] = a[0] + i;
        for (l = i = 0; i < 4; ++i) {
            for (j = 0; j < 4; ++j)
                for (k = 0; k < 4; ++k)
                    if (i != j && i != k && j != k)
                        printf("%d%s", a[i] * 100 + a[j] * 10 + a[k], ++l % 6 ? " " : "\n");
        }
    }
    return 0;
}
