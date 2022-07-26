#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *name;
    short course;
} record;

record rec[800000];

int cmp(const void *a, const void *b) {
    record *pa = (record *)a, *pb = (record *)b;
    if (pa->course == pb->course)
        return strcmp(pa->name, pb->name);
    return pa->course - pb->course;
}

int main() {
    int n, m, i, j, k, start, end;
    char stu[40000][5];
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    for (i = 0, j = 0; i < n; ++i) {
        scanf("%s %d", stu[i], &k);
        while (k--) {
            scanf("%d", &rec[j].course);
            rec[j++].name = stu[i];
        }
    }
    n = j;
    qsort(rec, n, sizeof(record), cmp);
    start = end = 0;
    for (i = 1; i <= m; ++i) {
        for (end = start; rec[end].course == i; ++end);
        if (end == start)
            printf("%d 0\n", i);
        else {
            printf("%d %d\n", i, end - start);
            for (j = start; j < end; ++j)
                printf("%s\n", rec[j].name);
            start = end;
        }
    }
    return 0;
}
