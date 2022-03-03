#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, top, cur;
	char line[128], stack[128][128];

	strcpy(stack[0], "http://www.acm.org/");
	while (scanf("%d\n\n", &n) != EOF) {
		while (n--) {
			cur = top = 0;
			while (1) {
				gets(line);
				if (!strncmp(line, "QUIT", 4))
					break;
				else if (!strncmp(line, "VISIT", 5)) {
					strcpy(stack[++cur], line + 6);
					top = cur;
					printf("%s\n", line + 6);
				}
				else if (!strncmp(line, "BACK", 4)) {
					if (cur > 0)
						printf("%s\n", stack[--cur]);
					else
						printf("%s\n", "Ignored");
				}
				else if (!strncmp(line, "FORWARD", 7)) {
					if (cur < top)
						printf("%s\n", stack[++cur]);
					else
						printf("%s\n", "Ignored");
				}
			}
			if (n)
				printf("\n");
		}
	}
	return 0;
}
