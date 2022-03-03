#include <stdio.h>

void revers(int s, int l, char *t)
{
	int i, j;
	char c;
	for (i = s, j = s + l - 1; i < j; i++, j--)
		c = t[i], t[i] = t[j], t[j] = c;
}

int main()
{
	int row, col, len, i, j;
	char s[256];
	freopen("input", "r", stdin);
	while (scanf("%d\n", &col) != EOF && col) {
		for (i = 0; (s[i] = getchar()) != '\n'; i++);
		len = i, row = len / col;
		if (row > 1)
			for (i = 1; i <= row; i += 2)
				revers(col * i, col, s);
		for (i = 0; i < col; i++)
			for (j = i; j < len; j += col)
				printf("%c", s[j]);
		printf("\n");
	}
	return 0;
}
