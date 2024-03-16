#include <stdio.h>
#include <string.h>

typedef struct {
    char *s;
    int id;
} expression;

expression g[128][8], x;
int n, m, k, prod[16], res[16], cnt[128];

int search(int w, int mask) {
    if (w == m)
        return 1;
    for (int i = 0; i < cnt[prod[w]]; ++i)
        if (!(g[prod[w]][i].id & mask)) {
            res[w] = i;
            if (search(w + 1, g[prod[w]][i].id | mask))
                return 1;
        }
    return 0;
}

int main() {
    int i, j, u, v, pos[128];
    char buf[1024], eql[64][128], self[32][4], *pl, *pr;
    freopen("input", "r", stdin);
    memset(pos, -1, sizeof(pos));
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &v);
        pos[v] = i;
        g[v][0].id = 1 << i;
        g[v][0].s = self[i];
        sprintf(g[v][0].s, "%02d ", v);
        cnt[v]++;
    }
    scanf("%d", &m);
    for (i = 0; i < m; ++i)
        scanf("%d", &prod[i]);
    scanf("%d\n", &k);
    while (k--) {
        fgets(buf, 1024, stdin);
        strcpy(eql[k], pl = strtok(buf, "->"));
        x.s = eql[k];
        x.id = 0;
        sscanf(strtok(NULL, "->"), "%d", &u);
        pr = strtok(pl, "+");
        do {
            sscanf(pr, "%d", &v);
            if (pos[v] < 0) {
                x.id = 0;
                break;
            }
            x.id |= 1 << pos[v];
        } while (pr = strtok(NULL, "+"));
        if (x.id) {
            for (i = cnt[u] - 1; i >= 0; --i) {
                if (strcmp(x.s, g[u][i].s) < 0)
                    g[u][i + 1] = g[u][i];
                else
                    break;
            }
            g[u][i + 1] = x;
            ++cnt[u];
        }
    }
    search(0, 0);
    for (i = 0; i < m; ++i)
        printf("%s-> %02d\n", g[prod[i]][res[i]].s, prod[i]);
    return 0;
}

