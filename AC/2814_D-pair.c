#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, k, l, d, surp;
	char s[128], pair[128][3];

	while (scanf("%s", s) != EOF && s[0] != '*') {
		surp = 1;
		l = strlen(s);
		for (d = 0; d + 1 < l && surp; d++) {
			for (i = 0; i + d + 1 < l && surp; i++) {
				pair[i][0] = s[i];
				pair[i][1] = s[i + d + 1];
				pair[i][2] = '\0';
				for (k = i - 1; k >= 0; k--)
					if (!strcmp(pair[i], pair[k])) {
						surp = 0;
						break;
					}
			}
		}
		if (surp)
			printf("%s is surprising.\n", s);
		else
			printf("%s is NOT surprising.\n", s);
	}
	return 0;
}
