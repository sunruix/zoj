#include <stdio.h>
#include <string.h>

void add(char *s, char *t)
{
	int i, c;
	for (i = 1022, c = 0; i >= 0; i--) {
		s[i] = s[i] - '0' + t[i] - '0' + c + '0';
		c = 0;
		if (s[i] > '9') {
			s[i] -= 10;
			c = 1;
		}
	}
}

void print(char *s)
{
	int i;
	for (i = 0; s[i] == '0'; i++);
	printf("%s\n", s + i);
}

int main()
{
	int n, i;
	char f1[1024], f2[1024];
	while (scanf("%d", &n) != EOF) {
		memset(f1, '0', sizeof(f1));
		memset(f2, '0', sizeof(f2));
		f1[1023] = f2[1023] = '\0';
		f1[1022] = f2[1022] = '1';
		for (i = 3; i <= n; i++) {
			if ((i % 2))
				add(f1, f2);
			else
				add(f2, f1);
		}
		if (n % 2)
			print(f1);
		else
			print(f2);
	}
	return 0;
}
