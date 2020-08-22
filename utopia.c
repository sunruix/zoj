#include <stdio.h>
#include <string.h>

int main()
{
    freopen("input", "r", stdin);
    int n, m, i, j, k, u, v, s[50005], a, b, c, x, ac, bc, ans;
    while (scanf("%d", &n) != EOF) {
        memset(s, -1, sizeof(s));
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &u, &v);
            u > v ? (s[u] = v) : (s[v] = u);
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d %d", &a, &b, &c);
            if (a == c || b == c) {
                printf("Yes\n");
                continue;
            }
            ac = bc = ans = 0;
            x = a;
            while (s[x] != -1 && s[x] != b && s[x] != c)    
                x = s[x];
            if (s[x] == b) {
                printf("Np\n");
                continue;
            }
            else if (s[x] == c)
                ac = 1;
            x = b;
            while (s[x] != )
                if (s[x] == c)
                    pc = 1;
                if (s[x] == b) {
                    ans = pc ? 1 : -1;
                    break;
                }
            }
            if (ans) {
                printf("%s\n", ans == 1 ? "Yes" : "No");
                continue;
            }
        }
    }
}