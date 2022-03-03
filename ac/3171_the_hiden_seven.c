#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	long long ans[8][10010];
	char s[10010], *t1 = "seven", *t2 = "SEVEN";

	while (fgets(s, sizeof(s), stdin)) {
		memset(ans, 0, sizeof(ans));
		for (i = 0; s[i] != '\0'; i++)
			if (s[i] == 's' || s[i] == 'S')
				ans[0][i] = 1;
		for (i = 0; t1[i] != '\0'; i++)
			for (j = 0; s[j] != '\0'; j++)
				ans[i + 1][j + 1] = t1[i] == s[j] || t2[i] == s[j] ? ans[i][j] + ans[i + 1][j] : ans[i + 1][j];
		printf("%lld\n", ans[strlen(t1)][strlen(s)]);
	}
	return 0;
}
