#include <stdio.h>

int main()
{
	int i, j;
	char s[3276888], t[3276888];

	while (scanf("%s %s", s, t) != EOF) {
		i = j = 0;
		while (s[i] != '\0' && t[j] != '\0') {
			if (s[i] == t[j])
				i++;
			j++;
		}
		if (s[i] == '\0')
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
