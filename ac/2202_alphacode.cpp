#include <stdio.h>

int main()
{
	int n, i, j, k, m[32768];
	char s[32768];
	freopen("input.txt", "r", stdin);
	while (scanf("%s", s + 1) != EOF && s[1] != '0') {
		for (i = 1, m[0] = 1, s[0] = '3'; s[i] != '\0'; i++) {
			m[i] = s[i] != '0' ? m[i - 1] : 0;
			if (s[i - 1] != '0' && 10 * (s[i - 1] - '0') + s[i] - '0' <= 26)
				m[i] += m[i - 2];
		}
		printf("%d\n", m[i - 1]);
	}
	return 0;
}