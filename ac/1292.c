#include <stdio.h>
#include <string.h>

int getline(char *s)
{
	int i = 0;
	while ((s[i++] = getchar()) != '\n');
	s[--i] = '\0';
	return i;
}

int main()
{
	int i, j, k, carry, aa, bb, N;
	char s[1024], t[1024], a[1024], b[1024], c[1024];

	scanf("%d\n\n", &N);
	while (N--) {
		memset(a, '0', sizeof(a));
		while (getline(s) >= 0 && strcmp(s, "0")) {
			memset(b, '0', sizeof(b));
			sprintf(b + 1023 - strlen(s), "%s", s);
			for (i = 1022, carry = 0; i >= 0; i--) {
				aa = a[i] - '0' + b[i] - '0' + carry;
				carry = 0;
				if (aa > 9)
					aa -= 10, carry = 1;
				a[i] = aa + '0';
			}
		}
		a[1023] = 0;
		for (i = 0; a[i] == '0'; i++);
		if (i < 1023)
			printf("%s\n", a + i);
		else
			printf("0\n");
		if (N)
			printf("\n");
	}
	return 0;
}
