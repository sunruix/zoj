#include <stdio.h>

void sort(int *a) {
    int i, j, k;
    for (i = 1; i < 4; ++i) {
        k = a[i];
        for (j = i - 1; k < a[j] && j >= 0; --j)
            a[j + 1] = a[j];
        a[j + 1] = k;
    }
}

void i2array(int n, int m[]) {
    m[0] = n / 1000;
    m[1] = n / 100 % 10;
    m[2] = n / 10 % 10;
    m[3] = n % 10;
}

int smaller(int m[]) {
    sort(m);
    return m[0] * 1000 + m[1] * 100 + m[2] * 10 + m[3];
}

int bigger(int m[]) {
    return m[3] * 1000 + m[2] * 100 + m[1] * 10 + m[0];
}

int main() {
    int n, m[4], a, b, c;
    while (scanf("%d", &n) != EOF) {
        a = b = c = -1;
        i2array(n, m);
        while (1) {
            b = smaller(m);
            a = bigger(m);
            if (c == a - b)
                break;
            c = a - b;
            printf("%04d - %04d = %04d\n", a, b, c);
            i2array(c, m);
        }
    }
    return 0;
}
