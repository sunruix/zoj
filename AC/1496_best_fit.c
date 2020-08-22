#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, ff, rr;
    double pi = 3.14159, f[4], r[16], d, target, diff, ans;
    scanf("%d\n", &n);
    while (n) {
        for (i = 0; i < 3; ++i)
            scanf("%lf", &f[i]);
        for (i = 0; i < 9; ++i)
            scanf("%lf", &r[i]);
        scanf("%lf %lf", &d, &target);
        diff = target;
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 9; ++j) {
                double a = f[i] / r[j] * d * pi;
                double b = fabs(a - target);
                if (b < diff) {
                    diff = b;
                    ans = a;
                    ff = f[i];
                    rr = r[j];
                }
            }
        }
        printf("A gear selection of %d/%d produces a gear size of %.3f.\n", ff, rr, ans);
        if (--n)
            printf("\n");
    }
    return 0;
}