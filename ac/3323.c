#include <stdio.h>

int main()
{
	int T;
	char c;
	scanf("%d\n", &T);
	while (T) {
		c = getchar();
		if (!(c >= '0' && c <= '9'))
			putchar(c);
		if (c == '\n')
			T--;
	}
	return 0;
}
