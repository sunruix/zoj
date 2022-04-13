#include <cstring>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N, L, K, visited[1001];
    vector<int> G[1001];
    deque<int> Q;
    freopen("input", "r", stdin);
    cin >> N >> L;
    for (int i = 1; i <= N; ++i) {
        int j, n;
        cin >> n;
        while (n--) {
            cin >> j;
            G[j].push_back(i);
        }
    }
    cin >> K;
    while (K--) {
        int v, l = 0, count = 0;
        cin >> v;
        memset(visited, 0, sizeof(visited));
        Q.clear();
        Q.push_back(v);
        Q.push_back(0);
        visited[v] = 1;
        while (!Q.empty() && l < L) {
            v = Q.front();
            Q.pop_front();
            if (0 == v) {
                ++l;
                Q.push_back(0);
                continue;
            }
            for (vector<int>::iterator it = G[v].begin(); it != G[v].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = 1;
                    Q.push_back(*it);
                    ++count;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}

