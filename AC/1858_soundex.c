#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	char c, s[32], ans[32], pre = 0;

	while (scanf("%s", s) != EOF) {
		memset(ans, 0, sizeof(ans));
		for (j = 0, i = 0, pre = 0; s[j] != '\0'; j++) {
			if (s[j] == 'B' || s[j] == 'F' || s[j] == 'P' || s[j] == 'V')
				ans[i++] = '1';
			else if (s[j] == 'C' || s[j] == 'G' || s[j] == 'J' || s[j] == 'K'
					|| s[j] == 'Q' || s[j] == 'S' || s[j] == 'X' || s[j] == 'Z')
				ans[i++] = '2';
			else if (s[j] == 'D' || s[j] == 'T')
				ans[i++] = '3';
			else if (s[j] == 'L')
				ans[i++] = '4';
			else if (s[j] == 'M' || s[j] == 'N')
				ans[i++] = '5';
			else if (s[j] == 'R')
				ans[i++] = '6';
			else
				ans[i++] = '0';
		}
		for (i = 0, pre = 0; ans[i] != '\0'; i++)
			if (ans[i] != pre) {
				pre = ans[i];
				if (ans[i] != '0')
					putchar(ans[i]);
			}
		putchar('\n');
	}
	return 0;
}
