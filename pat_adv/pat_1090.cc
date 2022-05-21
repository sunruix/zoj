#include <iostream>
#include <vector>

using namespace std;

int n, highest, count, root, v;
vector<int> G[100000];

void search(int u, int h) {
    if (G[u].empty()) {
        if (h > highest) {
            highest = h;
            count = 1;
        }
        else if (h == highest)
            ++count;
    }
    else
        for (vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it)
            search(*it, h + 1);
}

int main() {
    double p, r;
    freopen("input", "r", stdin);
    cin >> n >> p >> r;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        if (v == -1)
            root = i;
        else
            G[v].push_back(i);
    }
    search(root, 0);
    r = 1 + r / 100;
    for (int i = 0; i < highest; ++i)
        p *= r;
    printf("%.2f %d\n", p, count);
    return 0;
}
