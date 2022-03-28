#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int seq, roots[5005], checked[5005];
struct interval {
    int in, out;
} visit1[5005], visit2[5005];
vector<int> g1[5005], g2[5005], f, scc, ans;

void dfs1(int v) {
    if (visit1[v].in)
        return;
    visit1[v].in = ++seq;
    for (vector<int>::iterator it = g1[v].begin(); it != g1[v].end(); ++it)
        dfs1(*it);
    visit1[v].out = ++seq;
    f.push_back(v);
}

void dfs2(int v, int r, vector<int>& scc) {
    if (visit2[v].in)
        return;
    visit2[v].in = ++seq;
    for (vector<int>::iterator it = g2[v].begin(); it != g2[v].end(); ++it)
        dfs2(*it, r, scc);
    visit2[v].out = ++seq;
    scc.push_back(v);
    roots[v] = r;
}

int check(int v, int r) {
    if (roots[v] != r)
        return 0;
    if (checked[v])
        return 1;
    checked[v] = 1;
    for (vector<int>::iterator it = g1[v].begin(); it != g1[v].end(); ++it)
        if (!check(*it, r))
            return 0;
    return 1;
}

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF && n) {
        for (int i = 1; i <= n; ++i) {
            g1[i].clear();
            g2[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            if (v1 != v2) {
                g1[v1].push_back(v2);
                g2[v2].push_back(v1);
            }
        }
        memset(visit1, seq = 0, sizeof(visit1));
        f.clear();
        for (int i = 1; i <= n; ++i)
            dfs1(i);
        ans.clear();
        memset(visit2, seq = 0, sizeof(visit2));
        memset(roots, 0, sizeof(roots));
        for (int i = f.size() - 1; i >= 0; --i) {
            int v = f[i];
            if (!visit2[v].in) {
                scc.clear();
                dfs2(v, v, scc);
                memset(checked, 0, sizeof(checked));
                if (check(v, v))
                    for (vector<int>::iterator it = scc.begin(); it != scc.end(); ++it)
                        ans.push_back(*it);
            }
        }
        sort(ans.begin(), ans.end());
        for (vector<int>::iterator it = ans.begin(); it != ans.end() - 1; ++it)
            printf("%d ", *it);
        printf("%d\n", ans[ans.size() - 1]);
    }
    return 0;
}
