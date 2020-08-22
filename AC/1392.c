#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char s[256];
	freopen("input", "r", stdin);
	while (gets(s) && strcmp(s, "ENDOFINPUT")) {
		gets(s);
		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] >= 'A' && s[i] <= 'Z')
				printf("%c", 'A' + (s[i] - 'A' + 21) % 26);
			else
				printf("%c", s[i]);
		}
		printf("\n");
		gets(s);
	}
	return 0;
}
