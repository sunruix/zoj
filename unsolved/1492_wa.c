#include <stdio.h>
#include <string.h>

int hungary(int v, int n, int g[][64], int vis[], int m[], int sub[], int subn[])
{
    int w;

    for (w = 1; w <= n; w++)
        if (!g[v][w] && w != v && sub[v] == sub[w] && !vis[w]) {
            vis[w] = 1;
            if (!m[w] || hungary(m[w], n, g, vis, m, sub, subn)) {
                m[w] = v;
                return 1;
            }
        }
    return 0;
}

void dfs(int v, int n, int g[][64], int sub[], int index, int subn[])
{
    int w;

    sub[v] = index, subn[index]++;
    for (w = 1; w <= n; w++)
        if (g[v][w] && !sub[w])
            dfs(w, n, g, sub, index, subn);
}

int main()
{
    int n, i, j, g[64][64], vis[64], m[64], sub[64], subn[64], ans[64], max;

    while (scanf("%d", &n) != EOF && n) {
        memset(g, 0, sizeof(g)), memset(m, 0, sizeof(m));
        memset(sub, 0, sizeof(sub)), memset(ans, 0, sizeof(sub));
        memset(subn, 0, sizeof(subn));
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                scanf("%d", &g[i][j]);
        for (i = j = 1; i <= n; i++)
            sub[i] ? 0 : dfs(i, n, g, sub, j++, subn);
        for (i = 1; i <= n; i++) {
            memset(vis, 0, sizeof(vis));
            ans[sub[i]] += hungary(i, n, g, vis, m, sub, subn);
        }
        for (max = 0, i = 1; sub[i]; i++)
            max < (subn[i] - (ans[i] >> 1)) ? max = (subn[i] - (ans[i] >> 1)) : 0;
        printf("%d\n", max);
    }
    return 0;
}
