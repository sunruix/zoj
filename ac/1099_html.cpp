#include <stdio.h>
#include <string.h>

int main()
{
	int i = 0;
	char s[128];

	while (scanf("%s", s) != EOF) {
		if (!strcmp(s, "<br>"))
			printf("\n"), i = 0; 
		else if (!strcmp(s, "<hr>")) {
			if (i == 0)
				printf("-");
			else
				printf("\n-");
			for (i = 0; i < 78; i++)
				printf("-");
			printf("-\n"), i = 0;
		}
		else if (i == 0)
				printf("%s", s), i = strlen(s);
		else {
			i += 1 + strlen(s);
			if (i <= 80)
				printf(" %s", s);
			else
				printf("\n%s", s), i = strlen(s);
		}
	}
	printf("\n");
	return 0;
}