#include <stdio.h>
#include <string.h>

int search(char *s, char c, int a[][8], char *vis, char *path, int t, int target)
{
	int i;

	vis[c] = 1, path[t] = c;
	target += t & 1 ? -a[c][t] : a[c][t];
	if (t == 5) {
		vis[c] = 0;
		return target == 0;
	}
	for (i = 0; s[i] != '\0'; i++)
		if (!vis[s[i]] && search(s, s[i], a, vis, path, t + 1, target)) {
			vis[c] = 0;
			return 1;
		}
	vis[c] = 0;
	return 0;
}

int main()
{
	int target, a[128][8], i, j;
	char s[16], vis[128], path[8], ans[8];

	for (i = 'A'; i <= 'Z'; i++)
		for (a[i][0] = 1, j = 1; j <= 5; j++)
			a[i][j] = a[i][j - 1] * (i - 'A' + 1);
	memset(path, 0, sizeof(path));
	while (scanf("%d %s", &target, s) != EOF && (target || strcmp(s, "END"))) {
		memset(vis, 0, sizeof(vis));
		for (j = i = 0; s[i] != '\0'; i++)
			if (search(s, s[i], a, vis, path, 1, target)) {
				if (!j)
					j = 1, strcpy(ans, path + 1);
				else if (strcmp(path + 1, ans) > 0)
					strcpy(ans, path + 1);
			}
		if (!j)
			printf("no solution\n");
		else
			for (i = 0; i < 6; i++)
				printf("%c", i == 5 ? '\n' : ans[i]);
	}
	return 0;
}