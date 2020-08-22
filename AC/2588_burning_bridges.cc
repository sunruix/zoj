#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct edge {
    int u, v;
    bool inc, inv;
};

vector<int> path;
vector<struct edge> E;
vector<int> G[10001];
int visit[10001];

void dfs(int eid, int v)
{
    if (eid != -1)
        E[eid].inv = true;
    if (visit[v]) {
        if (eid != -1) {
            E[eid].inc = true;
            vector<int>::iterator it;
            for (it = path.end() - 1; it >= path.begin(); --it) {
                if (E[*it].u != v && E[*it].v != v)
                    E[*it].inc = true;
                else
                    break;
            }
            E[*it].inc = true;
        }
        return;
    }
    visit[v] = 1;
    if (eid != -1)
        path.push_back(eid);
    for (vector<int>::iterator it = G[v].begin(); it != G[v].end(); ++it)
        if (!E[*it].inv)
            dfs(*it, E[*it].u == v ? E[*it].v : E[*it].u);
    if (eid != -1)
        path.pop_back();
    visit[v] = 2;
}

int main()
{
    int t, n, m, i;
    vector<int> ans;
    cin >> t;
    while (t--) {
        memset(visit, 0, sizeof(visit));
        cin >> n >> m;
        for (i = 0; i < m; ++i) {
            struct edge e;
            e.inc = e.inv = false;
            cin >> e.u >> e.v;
            E.push_back(e);
            G[e.u].push_back(i);
            G[e.v].push_back(i);
        }
        for (i = 1; i <= n; ++i)
            dfs(-1, i);
        ans.clear();
        for (i = 0; i < m; ++i)
            if (!E[i].inc)
                ans.push_back(i + 1);
        cout << ans.size() << endl;
        for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
            cout << *it << (it == ans.end() - 1 ? '\n' : ' ');
        }
        if (t) {
            cout << endl;
            path.clear();
            E.clear();
            for (i = 1; i <= n; ++i)
                G[i].clear();
        }
    }
    return 0;
}