#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[8];
    int t, in;
} record;

int cmp(const void *a, const void *b) {
    record *pa = (record *)a, *pb = (record *)b;
    int res = strcmp(pa->id, pb->id);
    return res ? res : pa->t - pb->t;
}

int main() {
    int n, k, i, t, h, m, s, time[24 * 3600] = {0}, longest = 0, length, ln, lon[5000];
    char io[4] = {0}, *pre = io;
    record a[10000];
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i) {
        a[i].in = 0;
        scanf("%s %d:%d:%d %s", a[i].id, &h, &m, &s, io);
        a[i].in = io[0] == 'i';
        a[i].t = s + m * 60 + h * 3600;
    }
    qsort(a, n, sizeof(record), cmp);
    length = 0;
    for (i = 0; i < n - 1; ++i) {
        if (a[i].in && !a[i + 1].in && !strcmp(a[i].id, a[i + 1].id)) {
            if (strcmp(a[i].id, pre)) {
                pre = a[i].id;
                length = 0;
            }
            ++time[a[i].t];
            --time[a[i + 1].t];
            length += a[i + 1].t - a[i].t;
            if (length > longest) {
                ln = 0;
                lon[ln++] = i;
                longest = length;
            }
            else if (length == longest)
                lon[ln++] = i;
        }
    }
    for (i = 1; i < 24 * 3600; ++i)
        time[i] = time[i] ? (time[i - 1] + time[i]) : time[i - 1];
    while (k--) {
        scanf("%d:%d:%d", &h, &m, &s);
        t = h * 3600 + m * 60 + s;
        printf("%d\n", time[t]);
    }
    for (i = 0; i < ln; ++i)
        printf("%s ", a[lon[i]].id);
    h = longest / 3600;
    m = longest % 3600 / 60;
    s = longest % 3600 % 60;
    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}
