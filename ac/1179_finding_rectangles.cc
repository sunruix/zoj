#include <iostream>
#include <queue>

using namespace std;

struct point {
    char label;
    int x, y;
};

struct point* rec[4];
struct point a[32];
priority_queue<string, vector<string>, greater<string>> q;
int n;

void dfs(int corner)
{
    if (corner > 3) {
        string s({rec[0]->label, rec[1]->label, rec[2]->label, rec[3]->label});
        q.push(s);
    }
    else {
        for (int i = 0; i < n; ++i) {
            if ((corner == 1 && rec[0]->y == a[i].y && rec[0]->x < a[i].x) ||
                    (corner == 2 && rec[1]->x == a[i].x && rec[0]->y > a[i].y) ||
                    (corner == 3 && rec[2]->y == a[i].y && rec[0]->x == a[i].x)) {
                rec[corner] = &a[i];
                dfs(corner + 1);
            }
        }
    }
}

int main()
{
    int t = 0;
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i)
            cin >> a[i].label >> a[i].x >> a[i].y;
        for (int i = 0; i < n; ++i) {
            rec[0] = &a[i];
            dfs(1);
        }
        cout << "Point set " << ++t << ":";
        if (q.empty())
            cout << " No rectangles";
        else {
            int count = 0;
            cout << endl;
            while (!q.empty()) {
                cout << " " << q.top();
                q.pop();
                if (++count == 10 && !q.empty()) {
                    cout << endl;
                    count = 0;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
