#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float price, pt, amount;
} info;

int cmp(const void *a, const void *b) {
    if (((info *)a)->pt > ((info *)b)->pt)
        return -1;
    else
        return 1;
}

int main() {
    int n, i;
    info a[1024];
    float total, ans = 0;
    freopen("input", "r", stdin);
    scanf("%d %f", &n, &total);
    for (i = 0; i < n; ++i)
        scanf("%f", &a[i].amount);
    for (i = 0; i < n; ++i) {
        scanf("%f", &a[i].price);
        a[i].pt = a[i].price / a[i].amount;
    }
    qsort(a, n, sizeof(info), cmp);
    for (i = 0; i < n && total - a[i].amount > 0.001; total -= a[i++].amount)
        ans += a[i].price;
    if (total > 0 && i < n)
        ans += total * a[i].pt;
    printf("%.2f\n", ans);
    return 0;
}
