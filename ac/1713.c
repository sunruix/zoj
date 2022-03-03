#include <stdio.h>
#include <string.h>

int check (char c)
{
	if (c == 'a' || c == 'e' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'y')
		return 1;
	return 0;
}

int main()
{
	int i, j, count[3];
	char c, s[512];

	freopen("input", "r", stdin);
	while (1) {
		i = 0;
		while((c = getchar()) != '\n')
			s[i++] = c;
		s[i] = '\0';
		if (!strcmp(s, "e/o/i"))
			break;
		count[0] = count[1] = count[2] = j = 0;
		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] == '/')
				j++;
			else if (check(s[i]) && !check(s[i + 1]))
				count[j]++;
		}
		if (count[0] != 5)
			printf("%d\n", 1);
		else if (count[1] != 7)
			printf("%d\n", 2);
		else if (count[2] != 5)
			printf("%d\n", 3);
		else
			printf("Y\n");
	}
	return 0;
}
