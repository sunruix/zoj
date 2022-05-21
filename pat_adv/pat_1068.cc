#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x, mem[128][10000];
vector<int> a, ans;

int search(int pos, int left) {
    if (mem[left][pos])
        return mem[left][pos];
    if (a[pos] == left) {
        ans.push_back(a[pos]);
        return mem[left][pos] = 1;
    }
    if (a[pos] > left)
        return mem[left][pos] = -1;
    for (int i = pos + 1; i < n; ++i)
        if (search(i, left - a[pos]) > 0) {
            ans.push_back(a[pos]);
            return mem[left][pos] = 1; 
        }
    return mem[left][pos] = -1;
}

int main() {
    freopen("input", "r", stdin);
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(mem, 0, sizeof(mem));
        a.clear();
        ans.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n && search(i, m) < 0; ++i);
        if (ans.empty())
            printf("No Solution\n");
        else {
            for (int i = ans.size() - 1; i > 0; --i)
                printf("%d ", ans[i]);
            printf("%d\n", ans[0]);
        }
    }
    return 0;
}
