#include <stdio.h>

int main()
{
	int n, m, i, j, a[64], b[2][64];
	char c;

	scanf("%d", &n);
	for (i = 1; i <= 54; i++)
		scanf("%d", &a[i]), b[0][i] = i;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= 54; j++)
			b[i & 1][a[j]] = b[!(i & 1)][j];
	for (j = n & 1, i = 1; i <= 54; i++) {
		n = b[j][i] / 13, m = b[j][i] % 13;
		m ? 0 : (n--, m = 13);
		if (n == 0)
			c = 'S';
		else if (n == 1)
			c = 'H';
		else if (n == 2)
			c = 'C';
		else if (n == 3)
			c = 'D';
		else
			c = 'J';
		printf("%c%d%c", c, m, i == 54 ? '\n' : ' ');
	}
	return 0;
}
