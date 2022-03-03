#include <stdio.h>

int main()
{
	int n, i, j;
	char s[64];

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", s);
		printf("String #%d\n", i);
		for (j = 0; s[j] != '\0'; j++) {
			if (s[j] == 'Z')
				putchar('A');
			else
				putchar(s[j] + 1);
		}
		printf("\n\n");
	}
	return 0;
}