#include <stdio.h>
#include <string.h>

int Dijkstra(int src, int dst, int n, int g[][128])
{
    int i, j, min, known[128] = {0}, dis[128], pre[128];

    memset(dis, -1, sizeof(dis));
    while (!known[dst]) {
        dis[src] = 0;
        for (min = 0x7fffffff, j = -1, i = 0; i < n; i++)
            if (!known[i] && dis[i] >= 0 && dis[i] < min)
                min = dis[j = i];
        if (j == -1)
            break;
        for (known[j] = 1, i = 0; i < n; i++)
            if (g[j][i] >= 0 && i != j)
                if (dis[i] < 0 || dis[i] > dis[j] + g[j][i]) {
                    dis[i] = dis[j] + g[j][i];
                    pre[i] = j;
                }
    }
    if (dis[dst] >= 0)
        for (i = dst; i != src; i = pre[i]) {
            printf("[%d][%d]%d -> ", pre[i], i, g[pre[i]][i]);
            g[pre[i]][i] = -1;
        }
        printf("\n");
    return dis[dst];
}

int main()
{
    int n, i, j, k, g[128][128], sht, ans;
    freopen("input", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &g[i][j]);
        scanf("%d %d", &i, &j);
        if (i == j) {
            printf("inf\n");
            continue;
        }
        ans = (sht = Dijkstra(i, j, n, g)) >= 0 ? 1 : 0;
        while ((sht = Dijkstra(i, j, n, g)) >= 0);
        //while (ans && sht == Dijkstra(i, j, n, g))
            //++ans;
        printf("%d\n", ans);
    }
    return 0;
}