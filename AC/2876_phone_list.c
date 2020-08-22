#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int main()
{
	int T, n = 0, i, j, ans;
	char s[10001][16], t[16];

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%s", s[i]);
		qsort(s, n, sizeof(s[0]), comp);
		for (i = 0, ans = 1; i < n && ans; i++)
			for (j = strlen(s[i]) - 1; j > 0 && ans; j--) {
				strncpy(t, s[i], j), t[j] = '\0';
				if (bsearch(t, s, n, sizeof(s[0]), comp))
				ans = 0;
			}
			if (ans)
				printf("YES\n");
			else
				printf("NO\n");
	}
	return 0;
}
			