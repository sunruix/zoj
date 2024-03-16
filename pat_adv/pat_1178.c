#include <stdio.h>
#include <string.h>

typedef struct {
    int depth, upper;
} node;

int main() {
    int n, k, i, id, stack[1024], top = -1, path[1024], l;
    char buf[2048];
    node a[10000];
    freopen("input", "r", stdin);
    for (i = 0; i < 10000; ++i)
        a[i].depth = -1;
    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        fgets(buf, 2048, stdin);
        sscanf(buf, "%d", &id);
        a[id].depth = strlen(buf) - 4;
        if (top > 0) {
            while (a[id].depth < a[stack[top]].depth)
                --top;
            if (a[id].depth > a[stack[top]].depth)
                a[id].upper = stack[top];
            else
                a[id].upper = a[stack[top]].upper;
        }
        stack[++top] = id;
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &id);
        if (a[id].depth == -1)
            printf("Error: %04d is not found.\n", id);
        else {
            printf("0000");
            l = 0;
            while(id) {
                path[l++] = id;
                id = a[id].upper;
            }
            for (i = l - 1; i >= 0; --i)
                printf("->%04d", path[i]);
            printf("\n");
        }
    }
    return 0;
}
