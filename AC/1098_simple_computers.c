#include <stdio.h>

#define op (mem[pc] >> 5)
#define addr (mem[pc] & 0x1f)

int main()
{
    int n = 0, i;
    char accu;
    unsigned char s[32] = {0}, mem[32] = {0}, pc;
    while (scanf("%s", s) != EOF) {
        for (mem[n] = 0, i = 0; i < 8; ++i)
            mem[n] += (s[i] - '0' << 7 - i);
        if (++n == 32) {
            n = pc = accu = 0;
            while (op != 7) {
                switch (op) {
                    case 0:
                        mem[addr] = accu;
                        ++pc;
                        break;
                    case 1:
                        accu = mem[addr];
                        ++pc;
                        break;
                    case 2:
                        pc = accu ? pc + 1 : addr;
                        break;
                    case 3:
                        ++pc;
                        break;
                    case 4:
                        accu -= 1;
                        ++pc;
                        break;
                    case 5:
                        accu += 1;
                        ++pc;
                        break;
                    case 6:
                        pc = addr;
                        break;
                    case 7:
                        break;
                }
                pc %= 32;
            }
            for (i = 0; i < 8; ++i)
                printf("%d", (accu >> 7 - i) & 0x1);
            printf("\n");
        }
    }
    return 0;
}