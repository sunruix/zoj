#include <stdio.h>

int main()
{
    int t, n, m, i, pos, head, tail, r;
    char s[65536], result[65536], cmd[100001], c;

    scanf("%d\n\n", &t);
    while (t--) {
        scanf("%d", &n);
        getchar();
        r = pos = head = tail = 0;
        while(n--) {
            fgets(cmd, sizeof(cmd), stdin);
            for (i = 0; cmd[i] != '\n'; ++i)
                s[tail++] = cmd[i];
        }
        while((c = getchar()) != '#') {
            if (c == 'G' && head < tail)
                result[pos++] = s[r ? --tail : head++];
            else if (c == 'R')
                r = !r;
        }
        while ((c = getchar()) != '\n');

        for (i = 0; i < pos; ++i)
            printf("%c%s", result[i], i % 80 == 79 ? "\n" : "");
        if (i % 80 || i == 0)
            printf("\n");
        if (t)
            printf("\n");
    }

    return 0;
}
