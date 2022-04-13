#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int l, r;
} interval;

int split(const interval& root, interval& lchild, interval& rchild) {
    int n = root.r - root.l + 1, i = 0;
    lchild.l = root.l;
    rchild.r = root.r;
    while (n > (1 << i) - 1)
        ++i;
    int k = (1 << i) - 1 - n;
    if (!k) {
        int m = (root.l + root.r) >> 1;
        lchild.r = m - 1;
        rchild.l = m + 1;
    }
    else if (k < (1 << (i - 2))) {
        lchild.r = lchild.l + ((1 << i - 1) - 1) - 1;
        rchild.l = lchild.r + 2;
    }
    else {
        rchild.l = rchild.r - ((1 << i - 2) - 1) + 1;
        lchild.r = rchild.l - 2;
    }
    return lchild.r + 1;
}

int main () {
    int n, x;
    interval root, lchild, rchild;
    vector<int> a, ans;
    deque<interval> q;
    freopen("input", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    root.l = 0, root.r = n - 1;
    q.push_back(root);
    while (!q.empty()) {
        ans.push_back(a[split(q.front(), lchild, rchild)]);
        q.pop_front();
        if (lchild.l <= lchild.r)
            q.push_back(lchild);
        if (rchild.l <= rchild.r)
            q.push_back(rchild);
    }
    for (vector<int>::iterator it = ans.begin(); it != ans.end() - 1; ++it)
        cout << *it << ' ';
    cout << *(ans.end() - 1) << endl;
    return 0;
}

