#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char *s)
{
	int i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		if (s[i] != s[j])
			return 0;
	return 1;
}

int main()
{
	int i, j, k, max, carry, temp;
	char s[1024], t[1024], c;

	scanf("%s %d", s, &max);
	for (i = 0; i < max && !check(s); i++) {
		strcpy(t, s);
		for (j = 0, k = strlen(s) - 1; j < k; j++, k--)
			c = s[j], s[j] = s[k], s[k] = c; 
		for (j = strlen(s) - 1, carry = 0; j >= 0; j--) {
			temp = s[j] - '0' + t[j] - '0' + carry;
			carry = 0;
			if (temp > 9)
				carry = 1, temp -= 10;
			t[j] = temp + '0';
		}
		if (carry) {
			strcpy(s + 1, t);
			s[0] = '1';
		}
		else
			strcpy(s, t);
	}
	printf("%s\n%d\n", s, i);
	return 0;
}
