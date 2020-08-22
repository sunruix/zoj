#include <stdio.h>

#define INF 1e49

typedef struct {
    double slope, intercept;
} line;

int main()
{
    int n, x1, y1, x2, y2, x3, y3, x4, y4;
    line l1, l2;
    scanf("%d\n", &n);
    printf("INTERSECTING LINES OUTPUT\n");
    while (n--) {
        scanf("%d %d %d %d %d %d %d %d\n", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        l1.slope = x1 == x2 ? INF : (double)(y1 - y2) / (x1 - x2);
        l1.intercept = l1.slope == INF ? 0 : y1 - l1.slope * x1;
        l2.slope = x3 == x4 ? INF : (double)(y3 - y4) / (x3 - x4);
        l2.intercept = l2.slope == INF ? 0 : y3 - l2.slope * x3;
        if (l1.slope == l2.slope) {
            if (l1.slope == INF)
                printf("%s\n", x1 == x3 ? "LINE" : "NONE");
            else
                printf("%s\n", l1.intercept == l2.intercept ? "LINE" : "NONE");
        }
        else {
            double x, y;
            x = l1.slope == INF ? x1 : (l2.slope == INF ? x3 : (l2.intercept - l1.intercept) / (l1.slope - l2.slope));
            y = l1.slope == INF ? (l2.slope * x + l2.intercept) : l1.slope * x + l1.intercept;
            printf("POINT %.2f %.2f\n", x, y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}