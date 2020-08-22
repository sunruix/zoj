#include <stdio.h>
#include <string.h>

int main()
{
	int t, space = 0, tab = 0, i;
	char s[2048];

	scanf("%d\n", &t);
	while (t--) {
		while (fgets(s, 2048, stdin) && strcmp(s, "##\n")) {
			for (i = 0; s[i] != '\0' && s[i] != '\n'; i++)
				if (s[i] == '\t')
					tab++;
			for (i = strlen(s) - 2; i >= 0 && (s[i] == ' ' || s[i] == '\t'); i--)
				space += s[i] == ' ' ? 1 : 4;
		}
		printf("%d tab(s) replaced\n%d trailing space(s) removed\n", tab, space), tab = space = 0;
	}
	return 0;
}