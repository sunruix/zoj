#include <stdio.h>

int main()
{
	int N, i0, i1, j, k;
	int matrix[128][128], row_sum, col_sum[128], max = 0;

	scanf("%d", &N);
	for (i0 = 0; i0 < N; i0++)
		for (i1 = 0; i1 < N; i1++)
			scanf("%d", &matrix[i0][i1]);
	for (i0 = 0; i0 < N; i0++) {
		for (j = 0; j < N; j++)
			col_sum[j] = matrix[i0][j];
		for (i1 = i0; i1 < N; i1++) {
			row_sum = 0;
			for (j = 0; j < N; j++) {
				if (i1 > i0)
					col_sum[j] += matrix[i1][j];
				row_sum += col_sum[j];
				if (row_sum > max)
					max = row_sum;
				else if (row_sum < 0)
					row_sum = 0;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}

#include <stdio.h>
#include <string.h>

int matrix[4][4] = {0, -2, -7, 0, 9, 2, -6, 2, -4, 1, -4, 1, -1, 8, 0, -2};
int ps[4][4];

int main()
{
	int m = 4, n = 4, i, j, k;
	int sum[4], pos[4];
	int u0, u1, v0, v1, localmax;
	int S, max = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0)
				ps[i][j] = matrix[i][j];
			else
				ps[i][j] = ps[i - 1][j] + matrix[i][j];
		}
	}
	for (i = 0; i < m; i++) {
		for (j = i; j < m; j++) {
			memset(sum, 0, sizeof(sum));
			memset(pos, 0, sizeof(pos));
			localmax = 0;
			sum[0] = ps[j][0] - (i == 0 ? 0 : ps[i - 1][0]);
			for (k = 1; k < n; k++) {
				if (sum[k - 1] > 0) {
					sum[k] = sum[k - 1] + ps[j][k] - (i == 0 ? 0 : ps[i - 1][k]);
					pos[k] = pos[k - 1];
				}
				else {
					sum[k] = ps[j][k] - (i == 0 ? 0 : ps[i - 1][k]);
					pos[k] = k;
				}
				if (sum[k] > sum[localmax])
					localmax = k;
			}
			if (max < sum[localmax]) {
				max = sum[localmax];
				u0 = i; u1 = j;
				v0 = pos[localmax]; v1 = localmax;
			}
		}
	}

	printf("%d\n", max);
	for (i = u0; i <= u1; i++) {
		for (j = v0; j <= v1; j++)
			printf("%-4d", matrix[i][j]);
		printf("\n");
	}
	return 0;
}
						
#include <stdio.h>

int matrix[4][4] = {0, -2, -7, 0, 9, 2, -6, 2, -4, 1, -4, 1, -1, 8, 0, -2};
int map[4][4][4][4];

int main()
{
	int m = 4, n = 4, i, j, x0, x1, y0, y1;
	int u0, u1, v0, v1;
	int S, max = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			map[i][i][j][j] = matrix[i][j];
	for (x0 = 0; x0 < n; x0++)
		for (x1 = x0; x1 < n; x1++)
			for (y0 = 0; y0 < n; y0++)
				for (y1 = y0; y1 < n; y1++) {
					if (x0 != x1 && y0 != y1)
						map[x0][x1][y0][y1] = map[x0][x1 - 1][y0][y1 - 1] +
							map[x1][x1][y0][y1 - 1] + map[x0][x1 - 1][y1][y1] +
							matrix[x1][y1];
					else if (x0 == x1 && y0 != y1)
						map[x0][x1][y0][y1] = map[x0][x1][y0][y1 - 1] +
							matrix[x1][y1];
					else if (x0 != x1 && y0 == y1)
						map[x0][x1][y0][y1] = map[x0][x1 - 1][y0][y1] +
							matrix[x1][y1];
					S = map[x0][x1][y0][y1];
					if (S < 0)
						S = 0;
					if (S > max) {
						max = S;
						u0 = x0;
						u1 = x1;
						v0 = y0;
						v1 = y1;
					}
				}
	printf("%d\n", max);
	for (i = u0; i <= u1; i++) {
		for (j = v0; j <= v1; j++)
			printf("%-4d", matrix[i][j]);
		printf("\n");
	}
	return 0;
}
						
