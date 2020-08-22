#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, k, l, count;
	char s[1024 * 1024];
	while (scanf("%s", s) != EOF && strcmp(s, ".")) {
		l = strlen(s);
		count = 1;
		for (j = 1; j < l; j++) {
			if (l % j)
				continue;
			for (i = j; i < l && !strncmp(s, s + i, j); i += j);
			if (i >= l) {
				count = l / j;
				break;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
