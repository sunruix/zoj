#include <stdio.h>

int n, a[128], h[128], b[128];

int equal(int *a, int *b) {
    int i;
    for (i = 0; i < n && a[i] == b[i]; ++i);
    return i == n;
}

int insertion_sort(int *a, int pos) {
    int x = a[pos], i;
    for (i = pos - 1; i >= 0 && x < a[i]; --i)
        a[i + 1] = a[i];
    a[i + 1] = x;
}

void insert_heap(int *h, int x) {
    int cur, next;
    cur = ++h[0];
    while ((next = cur >> 1) && h[next] < x) {
        h[cur] = h[next];
        cur = next;
    }
    h[cur] = x;
}

void sort_heap(int *h) {
    int x = h[h[0]], p, q;
    h[h[0]--] = h[1];
    for (p = 1, q = p << 1; q <= h[0]; p = q, q = p << 1) {
        if (q + 1 <= h[0] && h[q + 1] > h[q])
            ++q;
        if (h[q] < x)
            break;
        h[p] = h[q];
    }
    h[p] = x;
}

int main() {
    int i, j, k;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        h[i + 1] = b[i];
    }
    for (i = 1; i <= n; ++i) {
        insertion_sort(a, i);
        if (equal(a, b)) {
            insertion_sort(a, i + 1);
            printf("Insertion Sort\n");
            for (j = 0; j < n - 1; ++j)
                printf("%d ", a[j]);
            printf("%d\n", a[j]);
            return 0;
        }
    }
    printf("Heap Sort\n");
    for (i = n; i > 0 && h[i] > h[1] && h[i] > h[i - 1]; --i);
    h[0] = i;
    sort_heap(h);
    for (j = 1; j <= n - 1; ++j)
        printf("%d ", h[j]);
    printf("%d\n", h[j]);
    return 0;
}
