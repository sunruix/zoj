#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, k, ii, jj, ls, lt, ans;
	char s[1024], t[128];

	while (scanf("%s %s", &s, &t) != EOF) {
		ls = strlen(s), lt = strlen(t);
		for (ans = i = 0; i + lt - 1 < ls; i++)
			for (j = 0; j < lt; j++) {
				for (k = 0, ii = i, jj = j; k < lt && s[ii] == t[jj]; k++, ii++, jj = (jj + 1) % lt);
				if (k == lt) {
					ans++;
					break;
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}