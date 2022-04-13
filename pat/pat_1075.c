#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id, total;
    char ac, avl;
} submit;

int cmp(const void *a, const void *b) {
    submit *pa = (submit *)a, *pb = (submit *)b;
    if (!pa->avl)
        return 1;
    if (pa->total != pb->total)
        return pb->total - pa->total;
    if (pa->ac != pb->ac)
        return pb->ac - pa->ac;
    return pa->id - pb->id;
}

int main() {
    int n, k, m, i, j, rank, id, p, ps, score[10001][6], full[6];
    submit sub[10001];
    memset(sub, 0, sizeof(sub));
    memset(score, -1, sizeof(score));
    freopen("input", "r", stdin);
    scanf("%d %d %d", &n, &k, &m);
    for (i = 1; i <= n; ++i)
        sub[i].id = i;
    for (i = 1; i <= k; ++i)
        scanf("%d", &full[i]);
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &id, &p, &ps);
        ps >= 0 ? (sub[id].avl = 1) : (ps = 0);
        if (score[id][p] < ps) {
            sub[id].total += score[id][p] < 0 ? ps : (ps - score[id][p]);
            score[id][p] = ps;
            if (score[id][p] == full[p])
                ++sub[id].ac;
        }
    }
    qsort(sub + 1, n, sizeof(submit), cmp);
    for (rank = i = 1; i <= n && sub[i].avl; ++i) {
        if (sub[i].total != sub[i - 1].total)
            rank = i;
        printf("%d %05d %d", rank, sub[i].id, sub[i].total);
        for (j = 1; j <= k; ++j)
            if (score[sub[i].id][j] >= 0)
                printf(" %d", score[sub[i].id][j]);
            else
                printf(" %c", '-');
        printf("\n");
    }
    return 0;
}
