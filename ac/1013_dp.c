#include <stdio.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int w1, s1, d1, w2, s2, d2, w3, s3, d3, w, s;
	int c1, c2, c3, d4;
	int record[2][501][501];
	int n, i, j, k, l, x, y;
	int i0, i1, j0, j1, max1, max2, max, set, m, count = 0;

	while (scanf("%d", &n) != EOF && n) {
		scanf("%d %d %d", &w1, &s1, &d1);
		scanf("%d %d %d", &w2, &s2, &d2);
		scanf("%d %d %d", &w3, &s3, &d3);
		scanf("%d %d %d %d", &c1, &c2, &c3, &d4);
		for (i = 0; i < 501; i++)
			for (j = 0; j < 501; j++)
				record[0][i][j] = record[1][i][j] = -1;
		record[0][0][0] = 0;
		for (l = 0; l < n; l++) {
			x = l & 1; y = !x;
			for (i = 0; i < 501; i++)
				for (j = 0; j < 501; j++)
					record[y][i][j] = -1;
			scanf("%d %d", &w, &s);
			for (i0 = 0; i0 * w1 <= w && i0 * s1 <= s; i0++) {
				for (j0 = 0; i0 * w1 + j0 * w2 <= w && i0 * s1 + j0 * s2 <= s; j0++) {
					k = min((w - i0 * w1 - j0 * w2) / w3, (s - i0 * s1 - j0 * s2) / s3);
					for (i1 = 0; i1 < 501 && record[x][i1][0] >= 0; i1++)
						for (j1 = 0; j1 < 501 && record[x][i1][j1] >= 0; j1++) {
							i = i0 + i1; j = j0 + j1;
							if (record[y][i][j] < 0 || record[y][i][j] < k + record[x][i1][j1])
								record[y][i][j] = k + record[x][i1][j1];
						}
				}
			}
		}
		x = n & 1;
		max = 0;
		for (i = 0; i < 501 && record[x][i][0] >= 0; i++)
			for (j = 0; j < 501 && record[x][i][j] >= 0; j++) {
				set = min(min(i / c1, j / c2), record[x][i][j] / c3);
				m = set * d4 + (i - set * c1) * d1 + (j - set * c2) * d2 +
					(record[x][i][j] - set * c3) * d3;
				if (max < m)
					max = m;
			}
		if (count)
			printf("\n");
		printf("Case %d: %d\n", ++count, max);
	}
	return 0;
}
