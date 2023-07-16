#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n, m, i, j, k, out[100001], pos, run[2][100001], len[2];
    priority_queue<int, vector<int>, greater<int>> q;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i)
        scanf("%d", &run[0][i]);
    len[0] = n;
    for (k = j = 0; k < n; j = !j) {
        len[!j] = pos = 0;
        for (i = 0; i < len[j]; ++i) {
            if (q.size() + len[!j] < m)
                q.push(run[j][i]);
            else {
                if (!q.empty()) {
                    out[pos++] = q.top();
                    q.pop();
                }
                if (run[j][i] >= out[pos - 1] && len[!j] < m)
                    q.push(run[j][i]);
                else
                    run[!j][len[!j]++] = run[j][i];
            }
        }
        while (!q.empty()) {
            out[pos++] = q.top();
            q.pop();
        }
        k += pos;
        for (i = 0; i < pos - 1; ++i)
            printf("%d ", out[i]);
        printf("%d\n", out[i]);
    }
    return 0;
}
