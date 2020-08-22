#include <stdio.h>
#include <string.h>

int main()
{
	int n, m, i, j, k;
	char s[16], a[16][16];

	while (scanf("%s", &s) != EOF && strcmp(s, "ENDOFINPUT")) {
		scanf("%d %d\n", &n, &m);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				a[i][j] = getchar() - '0';
			getchar();
		}
		for (i = 0; i < n - 1; i++) {
			for (j = 0; j < m - 1; j++)
				putchar((a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1]) / 4 + '0');
			putchar('\n');
		}
		scanf("%s", &s);
	}
	return 0;
}