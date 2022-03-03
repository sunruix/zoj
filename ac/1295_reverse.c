#include <stdio.h>
#include <string.h>

int main()
{
	int t, i;
	char s[128];
	scanf("%d", &t);
	gets(s);
	while (t--) {
		gets(s);
		for (i = strlen(s) - 1; i >= 0; i--)
			putchar(s[i]);
		putchar('\n');
	}
	return 0;
}
