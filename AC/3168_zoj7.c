#include <stdio.h>
#include <string.h>

int main()
{
	int i, z, o, j, seven;
	char c, s[1024];
	i = z = o = j = seven = 0;
	memset(s, 0, sizeof(s));
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			for (i = 0; i < z; i++)
				putchar('Z');
			for (i = 0; i < o; i++)
				putchar('O');
			for (i = 0; i < j; i++)
				putchar('J');
			for (i = 0; i < seven; i++)
				putchar('7');
			printf("%s\n", s);
			i = z = o = j = seven = 0;
			memset(s, 0, sizeof(s));
		}
		else if (c == 'Z')
			z++;
		else if (c == 'O')
			o++;
		else if (c == 'J')
			j++;
		else if (c == '7')
			seven++;
		else
			s[i++] = c;
	}
	return 0;
}
