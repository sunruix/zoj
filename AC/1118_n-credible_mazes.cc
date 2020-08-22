#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int n, m, s[32768], ca = 0;
map<vector<char>, int> nodes;
vector<pair<int, int>> ques;

int find(int x)
{
    while (s[x] >= 0)
        x = s[x];
    return x;
}

void uni(int x, int y)
{
    int r1 = find(x), r2 = find(y);
    if (r1 != r2)
        s[r1] = r2;
}

void connect(const vector<char>& v, int n)
{
    for (map<vector<char>, int>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        int res = 0;
        for (int i = 0; i < v.size(); ++i) {
            res += v[i] > it->first[i] ? v[i] - it->first[i] : it->first[i] - v[i];
        }
        if (res == 1)
            uni(n, it->second);
    }
}

int main()
{
    while (cin >> n && n) {
        m = 0;
        memset(s, -1, sizeof(s));
        nodes.clear();
        ques.clear();
        int x;
        vector<char> v;
        while (cin >> x && x >= 0) {
            int na, nb;
            v.push_back(x);
            for (int i = 1; i < n; ++i) {
                cin >> x;
                v.push_back(x);
            }
            map<vector<char>, int>::iterator it = nodes.find(v);
            if (it == nodes.end())
                na = nodes[v] = m++;
            else
                na = it->second;
            connect(v, na);
            v.clear();
            for (int i = 0; i < n; ++i) {
                cin >> x;
                v.push_back(x);
            }
            it = nodes.find(v);
            if (it == nodes.end())
                nb = nodes[v] = m++;
            else
                nb = it->second;
            connect(v, nb);
            ques.push_back(pair<int, int>(na, nb));
        }
        
        vector<pair<int, int>>::iterator it = ques.begin();
        for (; it != ques.end(); ++it) {
            if (find(it->first) != find(it->second))
                break;
        }
        cout << "Maze #" << ++ca << (it == ques.end() ? " can" : " cannot") << " be travelled" << endl;
    }
    return 0;
}