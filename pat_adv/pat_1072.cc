#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define MAX 0xFFFFFFFF

using namespace std;

typedef struct {
    unsigned u, v, d;
} edge;

int main() {
    int n, m, k, ds, ans;
    unsigned dist[1024][1024], max, total;
    char s1[4], s2[4];
    vector<edge> E;
    freopen("input", "r", stdin);
    while (scanf("%d %d %d %d", &n, &m, &k, &ds) != EOF) {
        E.clear();
        memset(dist, -1, sizeof(dist));
        ans = 0;
        max = 0;
        total = MAX;
        for (int i = 1; i <= n + m; ++i)
            dist[i][i] = 0;
        while (k--) {
            edge e;
            scanf("%s %s %d", s1, s2, &e.d);
            e.u = s1[0] == 'G' ? atoi(s1 + 1) + n : atoi(s1);
            e.v = s2[0] == 'G' ? atoi(s2 + 1) + n : atoi(s2);
            E.push_back(e);
        }
        for (int w = n + 1; w <= n + m; ++w) {
            for (int i = 0; i < n + m - 1; ++i)
                for (vector<edge>::iterator it = E.begin(); it != E.end(); ++it) {
                    if (dist[w][it->u] != MAX && dist[w][it->v] > dist[w][it->u] + it->d)
                        dist[w][it->v] = dist[w][it->u] + it->d;
                    if (dist[w][it->v] != MAX && dist[w][it->u] > dist[w][it->v] + it->d)
                        dist[w][it->u] = dist[w][it->v] + it->d;
                }
            unsigned local_total = 0, min = MAX;
            for (int i = 1; i <= n; ++i) {
                if (dist[w][i] <= ds) {
                    local_total += dist[w][i];
                    if (dist[w][i] < min)
                        min = dist[w][i];
                }
                else {
                    min = MAX;
                    break;
                }
            }
            if (min != MAX && ((max < min) || (max == min && local_total < total))) {
                    ans = w;
                    max = min;
                    total = local_total;
            }
        }
        if (ans)
            printf("G%d\n%.1f %.1f\n", ans - n, (float)max, (double)aver / 100);
        else
            printf("No Solution\n");
    }
    return 0;
}
