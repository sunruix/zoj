#include <stdio.h>

int main()
{
	int t, i, j, k, n, a[2][32][32], d[16], day, index;
	char map[4] = ".!X#";

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &day);
		for (i = 0; i < 16; i++)
			scanf("%d", &d[i]);
		for (i = 0; i < 20; i++)
			for (j = 0; j < 20; j++)
				scanf("%d", &a[0][i][j]);
		for (k = 1, n = 0; n < day; n++, k = !k)
			for (i = 0; i < 20; i++)
				for (j = 0; j < 20; j++) {
					index = (i ? a[!k][i - 1][j] : 0) + (j ? a[!k][i][j - 1] : 0) +
						(i < 19 ? a[!k][i + 1][j] : 0) + (j < 19 ? a[!k][i][j + 1] : 0) +
						a[!k][i][j];
					a[k][i][j] = a[!k][i][j] + d[index];
					if (a[k][i][j] > 3)
						a[k][i][j] = 3;
					if (a[k][i][j] < 0)
						a[k][i][j] = 0;
				}
		for (i = 0; i < 20; i++) {
			for (j = 0; j < 20; j++)
				printf("%c", map[a[!k][i][j]]);
			printf("\n");
		}
		t ? printf("\n") : 0;
	}
	return 0;
}