#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int);

int main()
{
    //freopen("input", "w", stdout);
    unsigned char c = 0;
    char cc = 0xf0;
    c = cc;
    printf("%c\n", c);
    return 0;
}

void func(int n)
{
    int i, j;
    srandom(time(NULL));
    printf("%d\n", n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)
            printf("%d ", (random() % 10) - 5);
        printf("\n");
    }
    printf("0 %d\n", n - 1);
}