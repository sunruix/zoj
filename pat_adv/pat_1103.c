#include <stdio.h>

int n, k, p, m, a[404], path[404], ans[404];
char mem[404][404][404];

int larger(int *p1, int *p2) {
    int i, sum1 = 0, sum2 = 0, res = 0;
    for (i = k - 1; i >= 0; --i) {
        sum1 += p1[i];
        sum2 += p2[i];
        res = p1[i] > p2[i];
    }
    return sum1 > sum2 || res;
}

int search(int left, int i, int step) {
    if (mem[left][i][step] || i > m || step == k)
        return 1;
    path[step] = i;
    if (left < a[i])
        return mem[left][i][step] = 1;
    else if (left == a[i] && step == k - 1) {
        if (larger(path, ans)) {
            int j;
            for (j = 0; j < k; ++j)
                ans[j] = path[j];
        }
        return 0;
    }
    else {
        int s1 = search(left - a[i], i, step + 1);
        int s2 = search(left - a[i], i + 1, step + 1);
        int s3 = search(left, i + 1, step);
        return mem[left][i][step] = s1 && s2 && s3;
    }
}

int main() {
    int i, j, x;
    freopen("input", "r", stdin);
    scanf("%d %d %d", &n, &k, &p);
    for (i = 1; a[i - 1] <= n; ++i) {
        for (x = 1, j = 0; j < p; ++j)
            x *= i;
        a[i] = x;
    }
    m = i - 2;
    search(n, 1, 0);
    if (!ans[0])
        printf("Impossible\n");
    else {
        printf("%d = ", n);
        for (i = k - 1; i > 0; --i)
            printf("%d^%d + ", ans[i], p);
        printf("%d^%d\n", ans[i], p);
    }
    return 0;
}
