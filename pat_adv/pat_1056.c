#include <stdio.h>

int main() {
    int np, ng, i, j, k, w[1024], rank[1024], q[2048], head = 0, tail = 0;
    freopen("input", "r", stdin);
    scanf("%d %d", &np, &ng);
    for (i = 0; i < np; ++i)
        scanf("%d", &w[i]);
    for (i = 0; i < np; ++i)
        scanf("%d", &q[i]);
    tail = np;
    while (tail - head != 1) {
        int r = (tail - head) / ng + ((tail - head) % ng ? 1 : 0) + 1;
        int rtail = tail;
        while (head != rtail) {
            int max = w[q[head]];
            int pmax = q[head++];
            for (i = 1; i < ng && head != rtail; ++i, ++head) {
                if (max < w[q[head]]) {
                    max = w[q[head]];
                    rank[pmax] = r;
                    pmax = q[head];
                }
                else
                    rank[q[head]] = r;
            }
            q[tail++] = pmax;
        }
    }
    rank[q[head]] = 1;
    for (i = 0; i < np - 1; ++i)
        printf("%d ", rank[i]);
    printf("%d\n", rank[i]);
    return 0;
}
