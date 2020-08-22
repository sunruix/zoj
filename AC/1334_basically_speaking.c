#include <stdio.h>
#include <string.h>

int convert1(char *s, int radix)
{
	int ans, a, i;

	for (i = 0, ans = 0; s[i] != '\0'; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a = s[i] - '0';
		else
			a = s[i] - 'A' + 10;
		ans = ans * radix + a;
	}
	return ans;
}

void convert2(char *s, int n, int radix)
{
	int i = 0, a;

	while (n) {
		a = n % radix;
		s[i++] = a <= 9 ? a + '0' : a - 10 + 'A';
		n /= radix;
	}
	s[i] = '\0';
}

int main()
{
	int i, j, radix1, radix2;
	char s[128], t[128];

	while (scanf("%s %d %d", s, &radix1, &radix2) != EOF) {
		convert2(t, convert1(s, radix1), radix2);
		if (strlen(t) > 7)
			printf("  ERROR\n");
		else {
			for (i = 0, j = strlen(t) - 1; j >= 0; i++, j--)
				s[i] = t[j];
			s[i] = '\0';
			printf("%7s\n", s);
		}
	}
	return 0;
}