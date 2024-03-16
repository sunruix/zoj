#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PUD 2
#define BIT(x) (1 << (x))

void func(int);

int main()
{
    unsigned short a;
    printf("%d\n", sizeof(unsigned));
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
