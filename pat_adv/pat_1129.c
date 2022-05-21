#include <stdio.h>

int main() {
    int n, k, a, i, j, count[65536] = {0}, *most[16] = {NULL}, *temp, size = 0;
    freopen("input", "r", stdin);
    scanf("%d %d", &n, &k);
    scanf("%d", &a);
    ++count[a];
    most[size++] = count + a;
    while (--n) {
        scanf("%d", &a);
        printf("%d: ", a);
        for (i = 0; i < size - 1; ++i)
            printf("%d ", most[i] - count);
        printf("%d\n", most[i] - count);
        ++count[a];
        if (count[a] == 1 && size < k)
            most[size++] = count + a;
        else if ((count[a] == *most[size - 1] && a < most[size - 1] - count) ||
                (count[a] - *most[size - 1] == 1 && a > most[size - 1] - count))
            most[size - 1] = count + a;
        for (i = 1; i < size; ++i) {
            temp = most[i];
            for (j = i - 1; j >= 0; --j) {
                if (*temp > *most[j] || (*temp == *most[j] && temp < most[j]))
                    most[j + 1] = most[j];
                else
                    break;
            }
            most[j + 1] = temp;
        }
    }
    return 0;
}
