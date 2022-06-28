#include <stdio.h>

void print_path(int *heap, int pos) {
    int ans[16], i, n = 0;
    for (i = pos; i >= 1; i >>= 1)
        ans[n++] = heap[i];
    for (i = n - 1; i > 0; --i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
}

int main() {
    int n, m, i, j, k, heap[2048], max = 1, min = 1;
    freopen("input", "r", stdin);
    scanf("%d\n%d", &n, &heap[1]);
    for (i = 2; i <= n; ++i) {
        scanf("%d", &heap[i]);
        if (heap[i] < heap[i >> 1])
            min = 0;
        if (heap[i] > heap[i >> 1])
            max = 0;
    }
    for (k = 0; (1 << k) <= n; ++k);
    for (i = (1 << k) - 1; i > n; i -= 2)
        if (i - 1 > n)
            print_path(heap, i >> 1);
    m = 1 << (k - 1);
    for (i = n; i >= m; --i)
        print_path(heap, i);
    printf("%s Heap\n", max ? "Max" : (min ? "Min" : "Not"));
    return 0;
}
