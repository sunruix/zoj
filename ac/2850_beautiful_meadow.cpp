#include <stdio.h>

int main()
{
	int m, n, i, j, a[16][16], yes;

	while (scanf("%d %d", &m, &n) != EOF && (m || n)) {
		for (i = 0, yes = 0; i < m; i++)
			for (j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				if (!a[i][j])
					yes = 1;
			}
		for (i = 0; i < m && yes; i++)
			for (j = 0; j < n && yes; j++)
				if (!a[i][j] && ((i > 0 && !a[i - 1][j]) || (j > 0 && !a[i][j - 1])))
					yes = 0;
		if (yes)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
				