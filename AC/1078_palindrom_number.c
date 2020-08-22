#include <stdio.h>
#include <string.h>

void make(int n, int basis, char *s)
{
	int i = 0, q, r;
	if (basis < 11) {
		while ((q = n / basis) != 0) {
			s[i++] = '0' + n % basis;
			n = q;
		}
		s[i] = '0' + n;
	}
	else {
		while ((q = n / basis) != 0) {
			r = n % basis;
			if (r >= 10)
				s[i++] = 'A' + r - 10;
			else
				s[i++] = '0' + r;
			n = q;
		}
		if (n >= 10)
			s[i] = 'A' + n - 10;
		else
			s[i] = '0' + n;
	}
}

int check(char *s)
{
	int i, j, len;
	len = strlen(s);

	for (i = 0, j = len - 1; i <= j && s[i] == s[j]; i++, j--);
	if (i < j)
		return 0;
	return 1;
}

int main()
{
	int n, basis, result[17], flag;
	char s[32];

	while (scanf("%d", &n) != EOF && n) {
		memset(result, 0, sizeof(result));
		flag = 0;
		for (basis = 2; basis <= 16; basis++) {
			memset(s, 0, 32);
			make(n, basis, s);
			if (check(s)) {
				result[basis] = 1;
				flag = 1;
			}
		}
		if (!flag)
			printf("Number %d is not a palindrom\n", n);
		else {
			printf("Number %d is palindrom in basis", n);
			for (basis = 2; basis <= 16; basis++)
				if (result[basis])
					printf(" %d", basis);
			printf("\n");
		}
	}
	return 0;
}

