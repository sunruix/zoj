#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n, m, id, k, u, v, l, max, level;
    vector<int> T[128];
    deque<int> Q;
    freopen("input", "r", stdin);
    cin >> n >> m;
    while (m--) {
        cin >> id >> k;
        while (k--) {
            cin >> v;
            T[id].push_back(v);
        }
    }
    Q.push_back(1);
    Q.push_back(0);
    max = l = level = 1;
    while (1) {
        v = Q.front();
        Q.pop_front();
        if (v == 0) {
            ++l;
            if (Q.size() > max) {
                max = Q.size();
                level = l;
            }
            if (Q.empty())
                break;
            else
                Q.push_back(0);
        }
        else {
            for (vector<int>::iterator it = T[v].begin(); it != T[v].end(); ++it)
                Q.push_back(*it);
        }
    }
    printf("%d %d\n", max, level);
    return 0;
}
