#include <stdio.h>

int main()
{
	int i, j;
	char s[32768], *kb = "1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./\0";
	while (gets(s)) {
		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] == ' ')
				putchar(s[i]);
			else {
				for (j = 0; kb[j] != '\0' && kb[j] != s[i]; j++);
				putchar(kb[j - 1]);
			}
		}
		putchar('\n');
	}
	return 0;
}
