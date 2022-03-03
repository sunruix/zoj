#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int s, w, c, k, m, rsc;

    while (cin >> s >> w >> c >> k >> m) {
        rsc = 10000;
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < k; ++i)
            q.push((i + 1) * m);
        int prev = 0;
        while (rsc > 0) {
            q.push(prev = max<int>(q.top() + s, prev - s) + w + s);
            q.pop();
            rsc -= c;
        }
        cout << prev << endl;
    }
    return 0;
}