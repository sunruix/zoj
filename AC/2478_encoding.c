#include <stdio.h>
#include <string.h>

int main()
{
	int N, i, count;
	char c, s[128];

	scanf("%d", &N);
	while (N--) {
		scanf("%s", s);
		c = s[0], count = 0;
		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] == c)
				count++;
			else {
				if (count > 1)
					printf("%d%c", count, c);
				else
					printf("%c", c);
				count = 1;
				c = s[i];
			}
		}
		if (count > 1)
			printf("%d%c", count, s[i - 1]);
		else
			printf("%c", s[i - 1]);
		printf("\n");
	}
	return 0;
}
