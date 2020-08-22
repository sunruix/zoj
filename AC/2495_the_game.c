#include <stdio.h>

int check(int n, int g[][32], int *x, int *y)
{
	int i, j, ii, jj, c1, c2, c3, c4;

	*x = *y = -1;
	for (i = 0; i < 19; i++)
		for (j = 0; j < 19; j++) {
			if (g[i][j] != n)
				continue;
			for (jj = j, c1 = 0; jj < 19 && g[i][jj] == n; jj++, c1++);
			for (ii = i, c2 = 0; ii < 19 && g[ii][j] == n; ii++, c2++);
			for (ii = i, jj = j, c3 = 0; ii < 19 && jj < 19 && g[ii][jj] == n; ii++, jj++, c3++);
			for (ii = i, jj = j, c4 = 0; ii >= 0 && jj < 19 && g[ii][jj] == n; ii--, jj++, c4++);
			if (c1 == 5 && (j == 0 || g[i][j - 1] != n))
				*x = i, *y = j;
			else if (c2 == 5 && (i == 0 || g[i - 1][j] != n))
				*x = i, *y = j;
			else if (c3 == 5 && ((i == 0 || j == 0) || g[i - 1][j - 1] != n))
				*x = i, *y = j;
			else if (c4 == 5 && ((i == 18 || j == 0) || g[i + 1][j - 1] != n))
				*x = i, *y = j;
		}
	if (*x >= 0)
		return 1;
	return 0;
}

int main()
{
	int t, i, j, k, g[32][32], x, y, ans;

	scanf("%d", &t);
	while (t--) {
		for (i = 0; i < 19; i++)
			for (j = 0; j < 19; j++)
				scanf("%d", &g[i][j]);
		if (check(1, g, &x, &y))
			printf("1\n%d %d\n", x + 1, y + 1);
		else if (check(2, g, &x, &y))
			printf("2\n%d %d\n", x + 1, y + 1);
		else
			printf("0\n");
	}
	return 0;
}