#include <stdio.h>

int main()
{
    int n, i, pos[8], x;
    char s[8];
    while (scanf("%d", &n) != EOF && n) {
        for (i = 1; i < 7; ++i)
            pos[i] = i;
        while (n--) {
            x = pos[6];
            scanf("%s", s);
            switch (s[0]) {
                case 'n':
                    pos[6] = pos[2], pos[2] = pos[1], pos[1] = pos[5], pos[5] = x;
                    break;
                case 's':
                    pos[6] = pos[5], pos[5] = pos[1], pos[1] = pos[2], pos[2] = x;
                    break;
                case 'e':
                    pos[6] = pos[4], pos[4] = pos[1], pos[1] = pos[3], pos[3] = x;
                    break;
                case 'w':
                    pos[6] = pos[3], pos[3] = pos[1], pos[1] = pos[4], pos[4] = x;
                    break;
            }
        }
        printf("%d\n", pos[1]);
    }
    return 0;
}