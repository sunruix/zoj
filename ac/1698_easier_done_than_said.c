#include <stdio.h>
#include <string.h>

int isvow(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int check1(char *s)
{
	while (*s)
		if (isvow(*s++))
			return 1;
	return 0;
}

int check2(char *s)
{
	int i;

	for (i = strlen(s) - 1; i > 1; i--)
		if (isvow(s[i]) == isvow(s[i - 1]) && isvow(s[i]) == isvow(s[i - 2]))
			return 0;
	return 1;
}

int check3(char *s)
{
	int i;

	for (i = strlen(s) - 1; i > 0; i--)
		if (s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o')
			return 0;
	return 1;
}

int main()
{
	char s[32];

	while (scanf("%s", s) != EOF && strcmp(s, "end")) {
		if (check1(s) && check2(s) && check3(s))
			printf("<%s> is acceptable.\n", s);
		else
			printf("<%s> is not acceptable.\n", s);
	}
	return 0;
}