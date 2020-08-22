#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, k, l, p, m, pm;
	char s[32], re[128];

	re['A'] = 'A', re['E'] = '3', re['H'] = 'H', re['I'] = 'I';
	re['J'] = 'L', re['L'] = 'J', re['M'] = 'M', re['O'] = 'O';
	re['S'] = '2', re['T'] = 'T', re['U'] = 'U', re['V'] = 'V';
	re['W'] = 'W', re['X'] = 'X', re['Y'] = 'Y', re['Z'] = '5';
	re['1'] = '1', re['2'] = 'S', re['3'] = 'E', re['5'] = 'Z', re['8'] = '8';
	while (scanf("%s", &s) != EOF) {
		for (p = m = pm = 1, i = 0, j = strlen(s) - 1; i <= j; i++, j--)
			if (s[i] != s[j] && re[s[i]] != s[j])
				p = m = pm = 0;
			else if (s[i] == s[j] && re[s[i]] != s[j])
				m = pm = 0;
			else if (s[i] != s[j] && re[s[i]] == s[j])
				p = pm = 0;
		printf("%s -- is ", s);
		if (pm)
			printf("a mirrored palindrome.\n\n");
		else if (p)
			printf("a regular palindrome.\n\n");
		else if (m)
			printf("a mirrored string.\n\n");
		else
			printf("not a palindrome.\n\n");
	}
	return 0;
}
