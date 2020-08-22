#include <stdio.h>
#include <string.h>

int main()
{
	int square[16][16], N, i, j, row[16], col[16], diag1, diag2, res;
	int record[1024];

	while (scanf("%d", &N) != EOF && N) {
		res = 1;
		memset(col, 0, sizeof(col));
		diag1 = diag2 = 0;
		for (i = 0; i < N; i++) {
			row[i] = 0;
			for (j = 0; j < N; j++) {
				scanf("%d", &square[i][j]);
				row[i] += square[i][j];
				col[j] += square[i][j];
				if (i == j)
					diag1 += square[i][j];
				if (i + j == N - 1)
					diag2 += square[i][j];
			}
		}
		if (diag1 != diag2)
			res = 0;
		for (i = 0; i < N && res; i++)
			if (row[i] != diag1 || col[i] != diag1)
				res = 0;
		for (i = 0; i < N && res; i++) {
			memset(record, 0, sizeof(record));
			for (j = 0; j < N && res; j++) {
				if (record[square[i][j]] == 0)
					record[square[i][j]] = 1;
				else
					res = 0;
			}
		}
		for (j = 0; j < N && res; j++) {
			memset(record, 0, sizeof(record));
			for (i = 0; i < N && res; i++) {
				if (record[square[i][j]] == 0)
					record[square[i][j]] = 1;
				else
					res = 0;
			}
		}
		if (res)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}


