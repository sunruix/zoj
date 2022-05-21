#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int m, n, s, r, i;
    string name;
    vector<string> ans;
    map<string, int> won;
    freopen("input", "r", stdin);
    cin >> m >> n >> s;
    m -= (--s);
    while (s--)
        cin >> name;
    for (r = 0, i = 0; i < m; ++i) {
        cin >> name;
        if (r == i % n) {
            if (won.find(name) != won.end())
                r = (r + 1) % n;
            else {
                won[name] = 1;
                ans.push_back(name);
            }
        }
    }
    if (ans.size())
        for (vector<string>::iterator it = ans.begin(); it != ans.end(); ++it)
            cout << *it << endl;
    else
        cout << "Keep going..." << endl;
    return 0;
}
