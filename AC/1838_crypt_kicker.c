#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int i, j, k, sol, count = 0;
	char s[128][128], map[32], *t = "the quick brown fox jumps over the lazy dog\0";

	while (gets(s[0])) {
		for (sol = i = 0; strcmp(s[i], ""); i++) {
			if (strlen(s[i]) == strlen(t)) {
				for (j = 0; !sol && t[j] != '\0'; j++)
					if ((islower(s[i][j]) && !islower(t[j])) || (!islower(s[i][j]) && islower(t[j])))
						break;
				if (!sol && t[j] == '\0') {
					memset(map, 0, sizeof(map));
					for (j = 0; t[j] != '\0'; j++) {
						if (t[j] == ' ')
							continue;
						if (!map[s[i][j] - 'a'] || map[s[i][j] - 'a'] == t[j])
							map[s[i][j] - 'a'] = t[j];
						else
							break;
					}
					if (t[j] == '\0') {
						for (k = 0; k < 26 && map[k]; k++);
						k == 26 ? sol = 1 : 0;
					}
				}
			}
			if (!gets(s[i + 1])) {
				i++;
				break;
			}
		}
		if (count++)
			printf("\n");
		if (sol) {
			for (j = 0; j < i; j++) {
				for (k = 0; s[j][k] != '\0'; k++)
					printf("%c", s[j][k] == ' ' ? ' ' : map[s[j][k] - 'a']);
				printf("\n");
			}
		}
		else
			printf("No solution.\n");
	}
	return 0;
}