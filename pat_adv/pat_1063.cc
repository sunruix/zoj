#include <cstdio>
#include <map>

using namespace std;

int main() {
    int n, m, k, a, b;
    map<int, int> l[51];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &a);
            l[i][a] = 1;
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &a, &b);
        if (l[a].size() > l[b].size())
            a ^= b, b ^= a, a ^= b;
        int count = 0;
        for (map<int, int>::iterator it = l[a].begin(); it != l[a].end(); ++it) {
            if (l[b].find(it->first) != l[b].end())
                ++count;
        }
        printf("%.1f%\n", (float)count / (l[a].size() + l[b].size() - count) * 100);
    }
    return 0;
}
