#include <stdio.h>

int main()
{
	int t, count;
	char c, pre;
	scanf("%d\n", &t);
	while (t--) {
		pre = getchar(), count = 1;
		while (1) {
			c = getchar();
			if (c == pre)
				count++;
			else {
				printf("%d%c", count, pre);
				pre = c;
				count = 1;
				if (c == '\n') {
					putchar(c);
					break;
				}
			}
		}
	}
	return 0;
}
