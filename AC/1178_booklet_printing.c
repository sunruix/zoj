#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, k, r;
    char pages[128][8], blank[8] = "Blank\0", *page_ptr[128];
    struct sheet {
        char *front0, *front1, *back0, *back1;
    } sheets[128 >> 2];

    for (i = 0; i < 128; ++i)
        sprintf(pages[i], "%d", i);
    while (scanf("%d", &n) != EOF && n) {
        printf("Printing order for %d pages:\n", n);
        if (n == 1)
            printf("Sheet 1, front: Blank, 1\n");
        else {
            r = n % 4;
            k = n / 4 + (r ? 1 : 0);
            for (i = 0; i <= n + 4 - r; ++i)
                page_ptr[i] = pages[i];
            if (r)
                for (i = 1; i <= 4 - r; ++i)
                    page_ptr[n + i] = blank;
            for (i = 1, j = 1, n += r ? (4 - r) : 0; i <= k; ++i, j += 2, n -= 2) {
                sheets[i].front0 = page_ptr[n];
                sheets[i].front1 = page_ptr[j];
                sheets[i].back0 = page_ptr[j + 1];
                sheets[i].back1 = page_ptr[n - 1];
            }
            for (i = 1; i <= k; ++i)
                printf("Sheet %d, front: %s, %s\nSheet %d, back : %s, %s\n",
                        i, sheets[i].front0, sheets[i].front1, i, sheets[i].back0, sheets[i].back1);
        }
    }
    return 0;
}