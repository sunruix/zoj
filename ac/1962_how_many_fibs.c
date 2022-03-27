#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

char fib[512][128];

int cmp(char *a, char *b) {
    int i;
    if (a[0] == b[0]) {
        for (i = a[0]; i > 0; --i) {
            if (a[i] != b[i])
                return a[i] - b[i];
        }
        return 0;
    }
    else
        return a[0] - b[0];
}

void add(char *a, char *b, char *c) {
    int i, l;
    for (l = max(a[0], b[0]), i = 1; i <= l; ++i) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
            c[i] -= 10;
            c[i + 1] += 1;
        }
    }
    c[0] = c[i] ? i : i - 1;
}

void convert(char *s) {
    int i, j;
    for (i = 1, j = s[0]; i < j; ++i, --j)
        swap(s[i], s[j]);
    for (i = 1; i <= s[0]; ++i)
        s[i] -= '0';
}

int main() {
    int i, j, k;
    char a[128], b[128];

    fib[1][0] = 1, fib[1][1] = 1;
    fib[2][0] = 1, fib[2][1] = 2;
    for (i = 3; i < 512; ++i)
        add(fib[i - 2], fib[i - 1], fib[i]);

    while (scanf("%s %s", a + 1, b + 1) != EOF && (strcmp(a + 1, "0") && strcmp(b + 1, "0"))) {
        a[0] = strlen(a + 1);
        b[0] = strlen(b + 1);
        convert(a);
        convert(b);
        for (i = 0; cmp(fib[i], a) < 0; ++i);
        for (j = i; cmp(fib[j], b) <= 0; ++j);
        printf("%d\n", j - i);
    }
    return 0;
}
