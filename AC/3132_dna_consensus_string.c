#include <stdio.h>
#include <string.h>

int main()
{
	int T, n, m, i, j, k, ans, count[128];
	char s[64][1024], t[1024], c;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (t[m] = '\0', i = 0; i < n; i++)
			scanf("%s", &s[i]);
		for (ans = j = 0; j < m; j++) {
			memset(count, 0, sizeof(count));
			for (i = 0; i < n; i++)
				count[s[i][j]]++;
			for (k = 0, i = 'A'; i <= 'T'; i++)
				if (k < count[i])
					k = count[i], c = (char)i;
			t[j] = c, ans += n - k;
		}
		printf("%s\n%d\n", t, ans);
	}
	return 0;
}