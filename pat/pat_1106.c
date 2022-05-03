#include <stdio.h>

int main() {
    int n, pt[100000], t[200000], q[200000], head, tail;
    double p, r;
    int i, j, k, u, v, shortest = 0, count = 0;
    freopen("input", "r", stdin);
    scanf("%d %lf %lf", &n, &p, &r);
    for (j = 0, i = 0; i < n; ++i) {
        pt[i] = j;
        scanf("%d", &t[j]);
        for (k = 1; k <= t[j]; ++k)
            scanf("%d", &t[j + k]);
        j += t[j] + 1;
    }
    head = tail = 0;
    q[tail++] = 0;
    q[tail++] = -1;
    while (1) {
        u = q[head++];
        if (u == -1) {
            if (head == tail || count)
                break;
            else {
                q[tail++] = -1;
                ++shortest;
            }
        }
        else {
            k = t[pt[u]];
            if (!k) {
                ++count;
                continue;
            }
            for (i = 1; i <= k; ++i)
                q[tail++] = t[pt[u] + i];
        }
    }
    r = (r / 100 + 1);
    for (i = 0; i < shortest; ++i)
        p *= r;
    printf("%.4f %d\n", p, count);
    return 0;
}
