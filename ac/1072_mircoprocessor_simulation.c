#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
    unsigned int pos, a, b, c, addr;

    while (scanf("%s", buf) != EOF && buf[0] != '8') {
        pos = 0;
        while (buf[pos] != '8') {
            switch (buf[pos++]) {
                case '0':
                    sscanf(buf + pos, "%2X", &addr);
                    sscanf(buf + addr, "%1X", &a);
                    pos += 2;
                    break;
                case '1':
                    sscanf(buf + pos, "%2X", &addr);
                    buf[addr] = a > 9 ? a - 10 + 'A' : a + '0';
                    pos += 2;
                    break;
                case '2':
                    a ^= b; b ^= a; a ^= b;
                    break;
                case '3':
                    c = a + b;
                    a = c & 0x0000000f;
                    b = c >> 4 & 0x0000000f;
                    break;
                case '4':
                    a = a + 1 & 0x0000000f;
                    break;
                case '5':
                    a = a - 1 & 0x0000000f;
                    break;
                case '6':
                    sscanf(buf + pos, "%2X", &addr);
                    pos = a ? pos + 2 : addr;
                    break;
                case '7':
                    sscanf(buf + pos, "%2X", &addr);
                    pos = addr;
                    break;
                default:
                    break;
            }
        }
        printf("%s\n", buf);
    }
    return 0;
}