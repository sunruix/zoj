#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct {
    string id;
    int gp, gm, gf, g, cert;
} score;

bool cmp(const score &a, const score &b) {
    if (a.cert != b.cert)
        return a.cert > b.cert;
    if (a.g != b.g)
        return a.g > b.g;
    return a.id < b.id;
}

int main() {
    int p, m, n, sc;
    map<string, score> list;
    vector<score> ans;
    score temp;
    string id;
    freopen("input", "r", stdin);
    cin >> p >> m >> n;
    temp.gp = temp.gm = temp.gf = temp.g = -1;
    for (int i = 0; i < p; ++i) {
        cin >> id >> temp.gp;
        list[id] = temp;
    }
    temp.gp = temp.gm = temp.gf = temp.g = -1;
    for (int i = 0; i < m; ++i) {
        cin >> id >> sc;
        map<string, score>::iterator it = list.find(id);
        if (it == list.end()) {
            temp.gm = sc;
            list[id] = temp;
        }
        else
            (it->second).gm = sc;
    }
    for (int i = 0; i < n; ++i) {
        cin >> id >> sc;
        map<string, score>::iterator it = list.find(id);
        if (it == list.end()) {
            temp.gf = sc;
            list[id] = temp;
        }
        else
            (it->second).gf = sc;
    }
    for (map<string, score>::iterator it = list.begin(); it != list.end(); ++it) {
        double gt;
        gt = (it->second).gm > (it->second).gf ? (double)(it->second).gm * 0.4 + (double)(it->second).gf * 0.6 : (it->second).gf;
        (it->second).g = (int)gt + ((int)(gt * 10) % 10 >= 5);
        (it->second).cert = (it->second).gp >= 200 && (it->second).g >= 60;
        (it->second).id = it->first;
        ans.push_back(it->second);
    }
    sort(ans.begin(), ans.end(), cmp);
    for (vector<score>::iterator it = ans.begin(); it != ans.end() && it->cert; ++it)
        printf("%s %d %d %d %d\n", it->id.c_str(), it->gp, it->gm, it->gf, it->g);
    return 0;
}
