#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, carry;
	char s[16];
	freopen("input", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		carry = 0;
		for (i = strlen(s) - 1; i > 0; i--) {
			if (s[i] - '0' + carry >= 5)
				carry = 1;
			else
				carry = 0;
			s[i] = '0';
		}
		s[0] += carry;
		if (s[0] > '9' || s[0] < 0)
			printf("10%s\n", s + 1);
		else
			printf("%s\n", s);
	}
	return 0;
}
