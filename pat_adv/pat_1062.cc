#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int id, vg, tg, g;
} info;

bool cmp(const info& a, const info& b) {
    return a.g == b.g ? (a.vg == b.vg ? a.id < b.id : a.vg > b.vg ) : a.g > b.g;
}

int main() {
    int n, m, l, h;
    vector<info> sage, noble, fool, other;
    freopen("input", "r", stdin);
    while (cin >> n >> l >> h) {
        m = 0;
        while (n--) {
            info x;
            cin >> x.id >> x.vg >> x.tg;
            if (x.vg < l || x.tg < l)
                continue;
            ++m;
            x.g = x.vg + x.tg;
            if (x.vg >= h && x.tg >= h)
                sage.push_back(x);
            else if (x.vg >= h && x.tg < h)
                noble.push_back(x);
            else if (x.vg >= x.tg)
                fool.push_back(x);
            else
                other.push_back(x);
        }
        sort(sage.begin(), sage.end(), cmp);
        sort(noble.begin(), noble.end(), cmp);
        sort(fool.begin(), fool.end(), cmp);
        sort(other.begin(), other.end(), cmp);
        cout << m << endl;
        for (vector<info>::iterator it = sage.begin(); it != sage.end(); ++it)
            cout << it->id << ' ' << it->vg << ' ' << it->tg << endl;
        for (vector<info>::iterator it = noble.begin(); it != noble.end(); ++it)
            cout << it->id << ' ' << it->vg << ' ' << it->tg << endl;
        for (vector<info>::iterator it = fool.begin(); it != fool.end(); ++it)
            cout << it->id << ' ' << it->vg << ' ' << it->tg << endl;
        for (vector<info>::iterator it = other.begin(); it != other.end(); ++it)
            cout << it->id << ' ' << it->vg << ' ' << it->tg << endl;
    }
    return 0;
}
