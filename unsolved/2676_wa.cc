#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int u, v, id;
    float c;
};

bool cmp_cost(const struct edge& e1, const struct edge& e2) {
    return e1.c < e2.c;
}

bool cmp_id(const struct edge& e1, const struct edge& e2) {
    return e1.id < e2.id;
}

void dfs(int i, int n, int G[][128], int *vis)
{
    if (vis[i])
        return;
    vis[i] = 1;
    for (int j = 1; j <= n; ++j)
        if (G[i][j])
            dfs(j, n, G, vis);
}

int main()
{
    int t = 0, n, m, G[128][128], vis[128];
    vector<struct edge> E;
    vector<int> ans;
    freopen("input", "r", stdin);
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(G, 0, sizeof(G));
        E.clear();
        ans.clear();
        for (int i = 0; i < m; ++i) {
            struct edge e;
            scanf("%d %d %f", &e.u, &e.v, &e.c);
            G[e.u][e.v] = G[e.u][e.v] = 1;
            e.id = i + 1;
            E.push_back(e);
        }
        sort(E.begin(), E.end(), cmp_cost);
        float total = 0;
        for (vector<struct edge>::iterator it = E.begin(); it != E.end(); ++it) {
            G[it->u][it->v] = G[it->v][it->u] = 0;
            ans.push_back(it->id);
            total += it->c;
            memset(vis, 0, sizeof(vis));
            dfs(1, n, G, vis);
            if (!vis[n])
                break;
        }
        sort(E.begin(), E.end(), cmp_id);
        sort(ans.begin(), ans.end());
        float aver = total / ans.size();
        for (int i = ans.size() - 1; i >= 0; --i) {
            struct edge& e = E[ans[i] - 1];
            if (!(e.c < aver)) {
                G[e.u][e.v] = G[e.v][e.u] = 1;
                memset(vis, 0, sizeof(vis));
                dfs(1, n, G, vis);
                if (!vis[n]) {
                    ans.erase(ans.begin() + i);
                    aver = (total - e.c) / ans.size();
                }
                else
                    G[e.u][e.v] = G[e.v][e.u] = 0;
            }
        }

        if (t++)
            printf("\n");
        printf("%d\n", ans.size());
        for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
            printf("%d%c", *it, it == ans.end() - 1 ? '\n': ' ');
    }
    return 0;
}
