#include <cstdio>
#include <vector>

using namespace std;

vector<int> g[100000];
int amount[100000];
double p, r;

double sale(int u, double price) {
    if (amount[u])
        return amount[u] * price;
    double val = 0.0;
    for (vector<int>::iterator it = g[u].begin(); it != g[u].end(); ++it)
        val += sale(*it, (1 + r / 100) * price);
    return val;
}

int main() {
    int n, k, v;
    freopen("input", "r", stdin);
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        if (k)
            while (k--) {
                scanf("%d", &v);
                g[i].push_back(v);
            }
        else {
            scanf("%d", &v);
            amount[i] = v;
        }
    }
    printf("%.1f\n", sale(0, p));
}
