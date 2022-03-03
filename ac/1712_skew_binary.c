#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, k;
	char s[64];

	while (scanf("%s", s) != EOF && strcmp(s, "0")) {
		for (i = strlen(s) - 1, j = 0, n = 0; i >= 0; i--, j++)
			n += ((2 << j) - 1) * (s[i] - '0');
		printf("%d\n", n);
	}
	return 0;
}
