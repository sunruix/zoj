#include <iostream>
#include <vector>

using namespace std;

int m, n, l, t, G[2][1286][128], seq = 2, dir[4][3] = {0, -1, 0, 0 , 1, 0, 0, 0, -1, 0, 0, 1};
vector<int> count;

int find(int w, int u, int v) {
    int r = G[w][u][v];
    while (count[r] < 0)
        r = -count[r];
    return r;
}

void unionn(int w, int u, int v, int z, int x, int y) {
    int r1 = find(w, u, v), r2 = find(z, x, y);

    if (r1 == 1 || r2 == 1)
        printf("%d %d\n", r1, r2);
    if (r1 < r2) {
        count[r1] += count[r2];
        count[r2] = -r1;
        G[z][x][y] = r1;
    }
    else if (r2 < r1) {
        count[r2] += count[r1];
        count[r1] = -r2;
        G[w][u][v] = r2;
    }
}

void spread(int w) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!G[w][i][j])
                continue;
            else if (G[w][i][j] == 1) {
                G[w][i][j] = seq++;
                count.push_back(1);
            }
            else
                ++count[find(w, i, j)];
            for (int k = 0; k < 4; ++k) {
                int u = i + dir[k][1];
                int v = j + dir[k][2];
                if (u >= 0 && u < m && v >= 0 && v < n) {
                    if (G[w][u][v] == 1)
                        G[w][u][v] = G[w][i][j];
                    else if (G[w][u][v] > 1)
                        unionn(w, u, v, w, i, j);
                }
            }
        }
    }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            G[w][i][j] = find(w, i, j);
}

int main() {
    freopen("input", "r", stdin);
    count.push_back(0);
    count.push_back(0);
    cin >> m >> n >> l >> t;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> G[0][i][j];
    for (int k = 1; k < l; ++k) {
        int x = k & 1;
        spread(!x);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                cin >> G[x][i][j];
                if (G[x][i][j] == 1 && G[!x][i][j])
                    G[x][i][j] = G[!x][i][j];
            }
    }
    spread(!(l & 1));
    int ans = 0;
    for (vector<int>::iterator it = count.begin(); it != count.end(); ++it)
        ans += *it >= t ? *it : 0;
    cout << ans << endl;
    return 0;
}
