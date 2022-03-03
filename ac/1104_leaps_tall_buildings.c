#include <stdio.h>
#include <math.h>

#define pi 3.1415927

int main()
{
    int n, m, i, j;
    double end, mid, h, d, x[256], y[256], slope, temp, a, b, top, t;
    freopen("input", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        for (end = 0, m = n <<1, i = j = 0; i < n; ++i, j += 2) {
            scanf("%lf %lf", &h, &d);
            x[j] = end;
            y[j] = y[j + 1] = h;
            x[j + 1] = (end += d);
        }
        mid = end / 2;
        slope = 0;
        for (j = i = 0; i < m; ++i) {
            temp = x[i] - mid < 1e-4 ? y[i] / x[i] : y[i] / (end - x[i]);
            if (slope < temp) {
                slope = temp;
                j = i;
            }
        }
        a = y[j] / (x[j] * x[j] - end * x[j]);
        b = -1 * a * end;
        top = -1 * b * b / (4 * a);
        t = sqrt(2 * top / 9.8);
        double vh = mid / t;
        double vv = top / t + 0.5 * 9.8 * t;

        printf("%.2f %.2f\n", atan(b) / pi * 180, sqrt(vh * vh + vv * vv));
    }
    return 0;
}