#include <stdio.h>
#include <string.h>

int key;

int l2c(char c)
{
	if (c == '_')
		return 0;
	if (c == '.')
		return 27;
	return c - 'a' + 1;
}

char c2l(int i)
{
	if (i == 0)
		return '_';
	if (i == 27)
		return '.';
	return 'a' + i - 1;
}

int plaincode(int i, char *msg)
{
	return l2c(msg[i]);
}

int main()
{
	int i, j;
	int ccode, pcode, len, tmp;
	char msga[72], msgb[72];
	while (scanf("%d", &key) != EOF && key !=0)
	{
		scanf("%s", msgb);
		memset(msga, 0, sizeof(msga));
		len = strlen(msgb);

		for (i = 0; i < len; i++)
		{
			ccode = plaincode(i, msgb);
			j = 0;
			while ((pcode = (ccode + i - 28 * j++)) >= 28);
			msga[key * i % len] = c2l(pcode);
		}
		printf("%s\n", msga);
	}
	return 0;
}
