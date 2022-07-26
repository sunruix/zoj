#include <stdio.h>

#define MAX_N 100000

int n, x, max, stack[100001], top = -1, bit[1 << 17];

int bit_sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void bit_add(int i, int x) {
    while (i <= MAX_N) {
        bit[i] += x;
        i += i & -i;
    }
}

int bsearch(int x) {
    int lb = -1, ub = MAX_N + 1;
    while (ub - lb > 1) {
        int m = (lb + ub) >> 1;
        if (bit_sum(m) >= x)
            ub = m;
        else
            lb = m;
    }
    return ub;
}

int main() {
    char cmd[16];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        scanf("%s", cmd);
        if (cmd[1] == 'u') {
            scanf("%d", &x);
            stack[++top] = x;
            bit_add(x, 1);
        }
        else if (cmd[1] == 'o') {
            if (top < 0)
                printf("Invalid\n");
            else {
                printf("%d\n", x = stack[top--]);
                bit_add(x, -1);
            }
        }
        else {
            if (top < 0)
                printf("Invalid\n");
            else
                printf("%d\n", bsearch(top + 2 >> 1));
        }
    }
    return 0;
}
