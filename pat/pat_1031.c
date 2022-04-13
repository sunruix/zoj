#include <stdio.h>
#include <string.h>

int main()
{
	int n, m, i, j, k, l;
	char s[128];

	scanf("%s", s);
	l = strlen(s);
	for (n = 3; n <= l; n++) {
		m = (l - n + 2);
		if (!(m % 2) && m / 2 <= n)
			break;
	}
	for (i = 0, j = l - 1, m = m / 2 - 1; i < m; i++, j--) {
		printf("%c", s[i]);
		for (k = 0; k < n - 2; k++)
			printf(" ");
		printf("%c\n", s[j]);
	}
	for (;i <= j; i++)
		printf("%c", s[i]);
	return 0;
}