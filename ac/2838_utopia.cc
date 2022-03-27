#include <cstdio>
#include <cstring>
#include <vector>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

using namespace std;

int seq;
struct interval {
    int in, out;
} visit[50000];
vector<int> g[50000];

void dfs(int v) {
    visit[v].in = ++seq;
    for (vector<int>::iterator it = g[v].begin(); it != g[v].end(); ) {
        if (visit[*it].in)
            g[v].erase(it);
        else {
            dfs(*it);
            ++it;
        }
    }
    visit[v].out = ++seq;
}

int main() {
    int n, m, t = 0;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            g[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        memset(visit, 0, sizeof(visit));
        dfs(seq = 0);
        printf("%sCase %d:\n", t ? "\n" : "", t + 1);
        ++t;
        scanf("%d", &m);
        while (m--) {
            int a, b, c, yes = 0;
            scanf("%d %d %d", &a, &b, &c);
            if (a == c || b == c)
                yes = 1;
            else if (a == b && a != c)
                yes = 0;
            else if ((visit[c].in > visit[a].out || visit[c].out < visit[a].in) &&
                    (visit[c].in > visit[b].out || visit[c].out < visit[b].in))
                yes = 0;
            else if (visit[c].in > visit[a].in && visit[c].out < visit[a].out)
                yes = (visit[c].in < visit[b].out && visit[c].out > visit[b].out);
            else if (visit[c].in > visit[b].in && visit[c].out < visit[b].out)
                yes = (visit[c].in < visit[a].out && visit[c].out > visit[a].out);
            else {
                if (!(visit[c].in < visit[a].in && visit[c].out > visit[a].out))
                    swap(a, b);
                if (visit[c].in > visit[b].out || visit[c].out < visit[b].in)
                    yes = 1;
                else if (!(visit[a].out < visit[b].in || visit[b].out < visit[a].in))
                    yes = 0;
                else {
                    int min_in = min(visit[a].in, visit[b].in);
                    int max_out = max(visit[a].out, visit[b].out);
                    int l = 0, r = g[c].size() - 1, m = (l + r) >> 1;
                    while (r - l > 1 && !yes) {
                        int v = g[c][m];
                        if (visit[v].in < min_in)
                            l = m;
                        else if (visit[v].in > min_in)
                            r = m;
                        else
                            yes = 1;
                        m = (l + r) >> 1;
                    }
                    if (!yes) {
                        int v = g[c][m];
                        if (m < g[c].size() - 1) {
                            int u = g[c][m + 1];
                            if (visit[u].in < min_in)
                                v = u;
                        }
                        yes = visit[v].out < max_out;
                    }
                }
            }
            printf("%s\n", yes ? "Yes" : "No");
        }
    }
    return 0;
}
