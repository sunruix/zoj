#include <stdio.h>
#include <string.h>

int main()
{
	int t, n, i, j, map[32][32], ans[32];
	char s[16];

	scanf("%d", &t);
	while (t--) {
		memset(map, 0, sizeof(map));
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%s", s);
			for (j = 0; s[j] != '\0'; j++)
				map[i][s[j] - 'A']++;
		}
		for (i = 0; i < 26; i++)
			for (j = 0, ans[i] = 13; j < n && ans[i]; j++)
				if (ans[i] > map[j][i])
					ans[i] = map[j][i];
		for (i = 0; i < 26; i++)
			for (j = 0; j < ans[i]; j++)
				putchar(i + 'A');
		putchar('\n');
	}
	return 0;
}