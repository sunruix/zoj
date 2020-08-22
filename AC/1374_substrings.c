#include <stdio.h>
#include <string.h>

int main()
{
	int T, n, i, j, k, ans, ls, lt;
	char s[128], t[128], m1[128][128], m2[128][128], mm1[128][128], mm2[128][128];

	scanf("%d", &T);
	while (T--) {
		memset(mm1, 0, sizeof(mm1)), memset(mm2, 0, sizeof(mm2));
		scanf("%d %s", &n, s + 1), ls = strlen(s + 1);
		for (k = 1; k < n; k++) {
			scanf("%s", t + 1), lt = strlen(t + 1);
			memset(m1, 0 ,sizeof(m1)), memset(m2, 0, sizeof(m2));
			for (i = 1; i <= ls; i++) {
				for (j = 1; j <= lt; j++) {
					m1[i][j] = s[i] == t[j] ? m1[i - 1][j - 1] + 1 : 0;
					m1[i][j] > mm1[k][i] ? mm1[k][i] = m1[i][j] : 0;
				}
				for (j = lt; j >= 1; j--) {
					m2[i][j] = s[i] == t[j] ? m2[i - 1][j + 1] + 1 : 0;
					m2[i][j] > mm2[k][i] ? mm2[k][i] = m2[i][j] : 0;
				}
			}
		}
		memset(mm1[0], 0x7f, sizeof(mm1[0]));
		for (i = 1; i < n; i++)
			for (j = 1; j <= ls; j++) {
				mm1[i][j] <= mm2[i][j] ? mm1[i][j] = mm2[i][j] : 0;
				mm1[0][j] > mm1[i][j] ? mm1[0][j] = mm1[i][j] : 0;
			}
		for (ans = 0, i = 1; i <= ls; i++)
			ans < mm1[0][i] ? ans = mm1[0][i] : 0;
		printf("%d\n", n == 1 ? ls : ans);
	}
	return 0;
}
