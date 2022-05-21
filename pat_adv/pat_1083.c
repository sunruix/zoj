#include <stdio.h>
#include <string.h>

typedef struct {
    char name[16], id[16];
    int grade;
} record;
record a[128];

int main() {
    int n, i, g, g1, g2, none = 1;
    char s1[16], s2[16];
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%s %s %d", s1, s2, &g);
        strcpy(a[g].name, s1);
        strcpy(a[g].id, s2);
    }
    scanf("%d %d", &g1, &g2);
    for (i = g2; i >= g1; --i)
        if (a[i].name[0]) {
            printf("%s %s\n", a[i].name, a[i].id);
            none = 0;
        }
    if (none)
        printf("NONE\n");
    return 0;
}
