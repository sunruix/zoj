#include <stdio.h>

int n, m, i, max, min, heap[2048], ans[1024], idx;

void postorder(int root) {
    if (root > n)
        return;
    postorder(root << 1);
    postorder((root << 1) + 1);
    ans[idx++] = heap[root];
}

int main() {
    freopen("input", "r", stdin);
    scanf("%d %d", &m, &n);
    while (m--) {
        min = max = 1;
        scanf("%d", &heap[1]);
        for (i = 2; i <= n; ++i) {
            scanf("%d", &heap[i]);
            heap[i] > heap[i >> 1] ? (max = 0) : (min = 0);
        }
        printf("%s Heap\n", min ? "Min" : (max ? "Max" : "Not"));
        idx = 0;
        postorder(1);
        for (i = 0; i < n - 1; ++i)
            printf("%d ", ans[i]);
        printf("%d\n", ans[i]);
    }
    return 0;
}
