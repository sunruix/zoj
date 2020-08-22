#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, k, map[32], ans;
	char s[1024];

	while (scanf("%d %s", &n, &s) != EOF && n) {
		memset(map, 0, sizeof(map));
		for (i = k = ans = 0; s[i] != '\0'; i++) {
			if (map[s[i] - 'A'] > 0)
				map[s[i] - 'A'] = 0, k--;
			else if (k < n)
				map[s[i] - 'A'] = 1, k++;
			else if (map[s[i] - 'A'] == 0)
				map[s[i] - 'A'] = -1, ans++;
		}
		if (ans)
			printf("%d customer(s) walked away.\n", ans);
		else
			printf("All customers tanned successfully\n");
	}
	return 0;
}