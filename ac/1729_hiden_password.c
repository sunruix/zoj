#include <stdio.h>
#include <string.h>

int main()
{
	int T, l, i, j, pos;
	char s[200002];

	scanf("%d", &T);
	while (T--) {
		scanf("%d %s", &l, s);
		for (i = 0; i < l; i++)
			s[i + l] = s[i];
		s[i + l] = '\0';
		for (i = 1, pos = 0; i < l; i++) {
			if (s[i] < s[i - 1]) {
				if ((j = strncmp(s + i, s + pos, l)) < 0)
					pos = i;
				else if (j == 0)
					break;
			}
		}
		printf("%d\n", pos);
	}
	return 0;
}
