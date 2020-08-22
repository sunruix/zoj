#include <stdio.h>
#include <string.h>

char m[5005][5005];

int main()
{
	int i, j, n, ans;
	char s[5005];
	freopen("input.txt", "r", stdin);
	while (scanf("%s", s) != EOF) {

		for (m[0][0] = 1, ans = n, i = 1; i < n; i++) {
			m[i][i] = 1;
			s[i] == s[i - 1] ? ans++, m[i - 1][i] = 1 : 0;
		}
		for (j = 3; j <= n; j++)
			for (i = 0; i + j <= n; i++)
				m[i + 1][i + j - 2] && s[i] == s[i + j - 1] ? ans++, m[i][i + j - 1] = 1 : 0;
		printf("%d\n", ans);
	}
	return 0;
}
