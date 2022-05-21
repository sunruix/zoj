#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int adj[8], est, area;
} pinfo;

typedef struct {
    int id, fm, est, area;
    double aver_est, aver_area;
} finfo;

int cmp(const void *a, const void *b) {
    finfo *pa = (finfo *)a, *pb = (finfo *)b;
    if (fabs(pa->aver_area - pb->aver_area) < 0.0001)
        return pa->id - pb->id;
    return pb->aver_area < pa->aver_area ? -1 : 1;
}

pinfo T[10000];
finfo ans[1000];
int n, visited[10000], idx;

void search(int id) {
    int i;
    if (id == -1 || visited[id])
        return;
    visited[id] = 1;
    ++ans[idx].fm;
    if (id < ans[idx].id)
        ans[idx].id = id;
    ans[idx].est += T[id].est;
    ans[idx].area += T[id].area;
    for (i = 1; i <= T[id].adj[0]; ++i)
        search(T[id].adj[i]);
}

int main() {
    int i, j, k, id, fa, mo, adj, idlist[1000];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &id);
        idlist[i] = id;
        scanf("%d %d %d", &fa, &mo, &T[id].adj[0]);
        for (j = 1; j <= T[id].adj[0]; ++j)
            scanf("%d", &T[id].adj[j]);
        if (fa >= 0)
            T[id].adj[++T[id].adj[0]] = fa;
        if (mo >= 0)
            T[id].adj[++T[id].adj[0]] = mo;
        for (j = 1; j <= T[id].adj[0]; ++j) {
            k = T[id].adj[j];
            T[k].adj[++T[k].adj[0]] = id;
        }
        scanf("%d %d", &T[id].est, &T[id].area);
    }
    for (idx = 0, i = 0; i < n; ++i) {
        if (!visited[idlist[i]]) {
            ans[idx].id = 10000;
            ans[idx].fm = ans[idx].est = ans[idx].area = 0;
            search(idlist[i]);
            ans[idx].aver_est = (double)ans[idx].est / ans[idx].fm;
            ans[idx].aver_area = (double)ans[idx].area / ans[idx].fm;
            ++idx;
        }
    }
    qsort(ans, idx, sizeof(finfo), cmp);
    printf("%d\n", idx);
    for (i = 0; i < idx; ++i)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].fm, ans[i].aver_est, ans[i].aver_area);
    return 0;
}
