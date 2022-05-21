#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char *s) {
    double x = atof(s);
    if (x > 1000 || x < -1000)
        return 0;
    int i, k = s[0] == '-' ? 1 : 0;
    for (i = k; s[i] >= '0' && s[i] <= '9'; ++i);
    if (s[i] == '\0')
        return 1;
    else if (s[i] == '.')
        return i + 3 >= strlen(s + k);
    else
        return 0;
}

int main() {
    int n, i, j, k, m = 0;
    double aver, sum = 0;
    char s[128];
    freopen("input", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        if (!check(s))
            printf("ERROR: %s is not a legal number\n", s);
        else {
            ++m;
            sum += atof(s);
        }
    }
    printf("The average of %d number%s is ", m, (!m || m > 1) ? "s" : "");
    if (m)
        printf("%.2f\n", sum / m);
    else
        printf("Undefined\n");
    return 0;
}
