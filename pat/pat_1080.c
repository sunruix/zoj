#include <stdio.h>
#include <stdlib.h>

#define tie(a, b) ((a).gf == (b).gf && (a).ge == (b).ge)

typedef struct {
    int id, ge, gi, ad;
    char app[8];
    float gf;
} applicant;

int cmp1(const void *a, const void *b) {
    applicant *pa = (applicant *)a, *pb = (applicant *)b;
    return pa->gf != pb->gf ? pb->gf - pa->gf : pb->ge - pa->ge;
}

int cmp2(const void *a, const void *b) {
    applicant *pa = (applicant *)a, *pb = (applicant *)b;
    return pa->ad != pb->ad ? pa->ad - pb->ad : pa->id - pb->id;
}

int main() {
    int N, M, K, school[128], last[128], i, j, ap;
    applicant a[40000];
    freopen("input", "r", stdin);
    scanf("%d %d %d", &N, &M, &K);
    for (i = 0; i < M; ++i) {
        scanf("%d", &school[i]);
        last[i] = -1;
    }
    for (i = 0; i < N; ++i) {
        a[i].id = i;
        a[i].ad = -1;
        scanf("%d %d", &a[i].ge, &a[i].gi);
        a[i].gf = ((float)a[i].ge + a[i].gi) / 2;
        for (j = 0; j < K; ++j)
            scanf("%d", &a[i].app[j]);
    }
    qsort(a, N, sizeof(applicant), cmp1);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < K; ++j) {
            ap = a[i].app[j];
            if (school[ap] > 0 || (school[ap] == 0 && last[ap] != -1 && tie(a[i], a[last[ap]]))) {
                a[i].ad = ap;
                if (!(school[ap] == 0 && last[ap] != -1 && tie(a[i], a[last[ap]])))
                    --school[ap];
                last[ap] = i;
                break;
            }
        }
    }
    qsort(a, N, sizeof(applicant), cmp2);
    for (i = 0; a[i].ad < 0; ++i);
    for (j = -1; i < N; ++i) {
        if (a[i].ad != j) {
            while (j != a[i].ad)
                printf("%s", j++ < 0 ? "" : "\n");
            printf("%d", a[i].id);
        }
        else
            printf(" %d", a[i].id);
    }
    for (++j; j < M; ++j)
        printf("\n");
    printf("\n");
    return 0;
}
