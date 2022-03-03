#include <stdio.h>
#include <string.h>

int main()
{
	int N, i, j, k, l, a[16], b[16], carry;
	char s[16], temp[16];

	while (scanf("%d", &N) != EOF && N) {
		memset(b, 0, sizeof(b));
		memset(temp, 0, sizeof(temp));
		while (N--) {
			scanf("%s", s);
			for (i = strlen(s) - 1, j = 15; i >= 0; i--) {
				if (s[i] >= '0' && s[i] <= '9')
					a[j--] = s[i] - '0';
			}
			a[j] = -1;
			for (j = 15; a[j] != -1; j--) {
				b[j] += a[j];
				if (b[j] >= 10) {
					b[j] -= 10;
					b[j - 1] += 1;
				}
			}
		}
		for (i = 0; i < 14; i++)
			if (b[i])
				break;
		if (i == 14)
			printf("$0.%d%d\n", b[14],b[15]);
		else {
			l = 14;
			for (j = 13, k = 1; j >= i; j--, k++) {
				temp[l--] = b[j] + '0';
				if (!(k % 3) && j != i)
					temp[l--] = ',';
			}
			printf("$%s.%d%d\n", temp + l + 1, b[14], b[15]);
		}
	}
	return 0;
}


