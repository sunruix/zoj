#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, p[100001], start, end, max, ans;
	char s[100001], t[100001];

	while (scanf("%s", &s) != EOF) {
		memset(t, 0, sizeof(t));
		for (j = 0, i = 0; s[i] != '\0'; i++) {
			if (s[i] == '(' || s[i] == '[')
				p[j++] = i;
			else if (j > 0) {
				if (s[i] == ')' && s[p[j - 1]] == '(' || s[i] == ']' && s[p[j - 1]] == '[')
					t[i] = t[p[--j]] = 1;
				else
					j = 0;
			}
		}
		for (max = i = 0; s[i] != '\0';) {
			for (; !t[i] && s[i] != '\0'; i++);
			for (start = i; t[i] && s[i] != '\0'; i++);
			if (max < i - start)
				max = i - start, ans = start, end = i;
		}
		printf("%.*s\n\n", max, s + ans);
	}
	return 0;
}