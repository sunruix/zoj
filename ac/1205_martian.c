#include <stdio.h>
#include <string.h>

int toint(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else
		return c - 'a' + 10;
}

char tochar(int i)
{
	if (i <= 9)
		return '0' + i;
	else
		return 'a' + i - 10;
}

int main()
{
	int i, j, k, carry, aa, bb, cc;
	char a[128], b[128], c[128], s[128], t[128];

	while (scanf("%s %s", s, t) != EOF) {
		carry = 0;
		memset(a, '0', sizeof(a));
		memset(b, '0', sizeof(b));
		memset(c, 0, sizeof(c));
		sprintf(a + 127 - strlen(s), "%s", s);
		sprintf(b + 127 - strlen(t), "%s", t);
		for (i = j = k = 126; i >= 0; i--, j--, k--) {
			aa = toint(a[i]), bb = toint(b[j]);
			cc = (aa + bb + carry);
			carry = 0;
			if (cc > 19)
				cc -= 20, carry = 1;
			c[k] = tochar(cc);
		}
		for (i = 0; c[i] == '0'; i++);
		if (i < 127)
			printf("%s\n", c + i);
		else
			printf("0\n");
	}
	return 0;
}
