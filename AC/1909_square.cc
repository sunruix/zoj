#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[32];
vector<int> path;
vector<vector<int>> path_list;

bool intsect(vector<int>& v1, vector<int>& v2)
{
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
        if (binary_search(v2.begin(), v2.end(), *it))
            return true;
    return false;
}

void merge(vector<int>& v1, vector<int>& v2)
{
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
        v1.push_back(*it);
}

void dfs(int i, int n, int left)
{
    if (!left) {
        path_list.push_back(path);
        return;
    }
    if (i == n)
        return;
    if (left >= a[i]) {
        path.push_back(i);
        dfs(i + 1, n, left - a[i]);
        path.pop_back();
    }
    dfs(i + 1, n, left);
}

bool dfs2(int i, int n, int left)
{
    if (!left)
        return true;
    if (i == n)
        return false;
    if (!intsect(path, path_list[i])) {
        merge(path, path_list[i]);
        if (dfs2(i + 1, n, left - 1))
            return true;
        path.resize(path.size() - path_list[i].size());
    }
    return dfs2(i + 1, n, left);
}

int main()
{
    int t, n, m, i, l;
    freopen("input", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (l = i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            l += a[i];
        }
        if (l & 3)
            cout << "no" << endl;
        else {
            path.clear();
            path_list.clear();
            dfs(0, n, l >>= 2);

            path.clear();
            if (dfs2(0, path_list.size(), 4))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}