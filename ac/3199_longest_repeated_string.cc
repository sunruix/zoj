#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int t, n, i, j, k, ans;
    char c, s[50005];
    vector<int> g[128];

    scanf("%d\n", &t);
    while (t--) {
        for (i = 0; i < 128; i++)
            g[i].clear();
        scanf("%s", s);
        for (n = 0; s[n] != '\0'; ++n)
            g[s[n]].push_back(n);
        ans = 0;
        for (c = 'a'; c <= 'z'; ++c) {
            if (!g[c].size())
                continue;
            for (vector<int>::iterator it = g[c].begin(); it != g[c].end() - 1; ++it) {
                for (vector<int>::iterator jt = it + 1; jt != g[c].end(); ++jt) {
                    i = (*it);
                    j = (*jt);
                    int l = j - i;
                    if (l <= n - j && l > ans) {
                        for (k = 1; k < l && s[i + k] == s[j + k]; ++k);
                        if (k == l)
                            ans = l;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
