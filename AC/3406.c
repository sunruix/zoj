#include <stdio.h>

int main()
{
	int count, i;
	char c, word[128];

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			for (i = 0; (c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z'); c = getchar())
				word[i++] = c;
			putchar(word[0]);
			if (i > 2)
				printf("%d", i - 2);
			if (i > 1)
				putchar(word[i - 1]);
			putchar(c);
		}
		else
			putchar(c);
	}
	return 0;
}
