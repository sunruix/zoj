#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct {
    int dst, cost;
} edge;

map<string, int> mp;
vector<edge> G[256];
vector<int> path, apath;
int n, m, dest, h[256], mincost, maxh, averh, mincount, inpath[256];

void search(int u, int cost, int happy, int l) {
    if (inpath[u])
        return;
    inpath[u] = 1;
    path.push_back(u);
    if (u == dest) {
        if (cost < mincost) {
            mincost = cost;
            mincount = 1;
            apath = path;
            maxh = happy;
            averh = happy / l;
        }
        else if (cost == mincost) {
            ++mincount;
            if (happy > maxh) {
                apath = path;
                maxh = happy;
                averh = happy / l;
            }
            else if (happy == maxh && (happy / l) > averh) {
                apath = path;
                averh = happy / l;
            }
        }
    }
    else {
        for (vector<edge>::iterator it = G[u].begin(); it != G[u].end(); ++it) {
            search(it->dst, cost + it->cost, happy + h[it->dst], l + 1);
        }
    }
    inpath[u] = 0;
    path.pop_back();
}

int main() {
    freopen("input", "r", stdin);
    string cities[256];
    cin >> n >> m >> cities[1];
    mp[cities[1]] = 1;
    for (int i = 2; i <= n; ++i) {
        cin >> cities[i];
        mp[cities[i]] = i;
        cin >> h[i];
        if (cities[i] == "ROM")
            dest = i;
    }
    for (int i = 0; i < m; ++i) {
        string city1, city2;
        int u, v;
        edge e;
        cin >> city1 >> city2 >> e.cost;
        u = mp[city1];
        v = mp[city2];
        e.dst = v;
        G[u].push_back(e);
        e.dst = u;
        G[v].push_back(e);
    }
    mincost = 0x7fffffff;
    search(1, 0, 0, 0);
    cout << mincount << ' ' << mincost << ' ' << maxh << ' ' << averh << endl;
    for (vector<int>::iterator it = apath.begin(); it != apath.end() - 1; ++it)
        cout << cities[*it] << "->";
    cout << "ROM" << endl;
    return 0;
}
