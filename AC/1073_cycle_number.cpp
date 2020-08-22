#include <stdio.h>
#include <string.h>

int add(char *s, char *t)
{
	int i, carry;
	
	for (i = strlen(s) - 1, carry = 0; i >= 0; i--) {
		s[i] = s[i] - '0' + t[i] - '0' + carry;
		carry = 0;
		if (s[i] > 9)
			s[i] -= 10, carry = 1;
		s[i] += '0';
	}
	return !carry;
}

int check(char *s, char *t)
{
	int i, j, k;

	for (i = strlen(s) - 1; i >= 0; i--) {
		for (j = 0, k = i; t[j] != '\0'; j++, k++) {
			if (s[k] == '\0')
				k = 0;
			if (s[k] != t[j])
				break;
		}
		if (t[j] == '\0')
			return 1;
	}
	return 0;
}

	

int main()
{
	int ans, i;
	char s[64], t[64];

	while (scanf("%s", t) != EOF) {
		ans = t[0] >= '5' ? 0 : 1;
		for (i = strlen(t) - 2, strcpy(s, t); i >= 0 && ans; i--) {
			ans = add(s, t);
			ans = ans ? check(s, t) : ans;
		}
		if (ans)
			printf("%s is cyclic\n", t);
		else
			printf("%s is not cyclic\n", t);
	}
	return 0;
}