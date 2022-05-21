#include <stdio.h>

int equal(int *a, int *b, int n) {
    int i;
    for (i = 0; i < n && a[i] == b[i]; ++i);
    return i == n;
}

void insertion_sort(int *a, int n, int i) {
    int j, x = a[i];
    for (j = i - 1; j >= 0 && a[j] > x; --j)
        a[j + 1] = a[j];
    a[j + 1] = x;
}

void merge_sort(int *a, int n, int l) {
    int i, j, k, start, b[256];
    for (start = 0; start < n; start += (l << 1)) {
        for (i = k = start, j = i + l; j < n && i < start + l && j < start + l + l; )
            b[k++] = a[i] < a[j] ? a[i++] : a[j++];
        for ( ; i < start + l; b[k++] = a[i++]);
        for ( ; j < n && j < start + l + l; b[k++] = a[j++]);
    }
    for (i = 0; i < n; ++i)
        a[i] = b[i];
}

int main() {
    int n, i, a1[256], a2[256], b[256];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a1[i]);
        a2[i] = a1[i];
    }
    for (i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    for (i = 1; i < n; ++i) {
        insertion_sort(a1, n, i);
        if (equal(a1, b, n))
            break;
    }
    if (i < n) {
        printf("Insertion Sort\n");
        insertion_sort(a1, n, i + 1);
        for (i = 0; i < n - 1; ++i)
            printf("%d ", a1[i]);
        printf("%d\n", a1[i]);
    }
    else {
        printf("Merge Sort\n");
        for (i = 1; i < n; i <<= 1) {
            merge_sort(a2, n, i);
            if (equal(a2, b, n))
                break;
        }
        merge_sort(a2, n, i << 1);
        for (i = 0; i < n - 1; ++i)
            printf("%d ", a2[i]);
        printf("%d\n", a2[i]);
    }
    return 0;
}
