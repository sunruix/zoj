#include <stdio.h>
#include <string.h>

int main()
{
	int m, n, i, j, k;
	char c;
	char s[128][128];

	scanf("%d", &m);
	while (m--) {
		scanf("%d%c", &n, &c);
		while (n--) {
			memset(s, 0, sizeof(s));
			i = 0; j = 0;
			while ((c = getchar()) != '\n') {
				if (c == ' ') {
					i++;
					j = 0;
				}
				else
					s[i][j++] = c;
			}
			k = i;
			for (i = 0; s[i][0] != '\0'; i++) {
				for (j = strlen(s[i]) - 1; j >= 0; j--)
					printf("%c", s[i][j]);
				if (i != k)
					printf(" ");
			}
			printf("\n");
		}
		if (m)
			printf("\n");
	}
	return 0;
}

