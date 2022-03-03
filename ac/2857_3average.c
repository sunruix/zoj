#include <stdio.h>

int main()
{
	int N, M, i, j, k, temp, m[128][128], t = 1;

	while (scanf("%d %d", &N, &M) != EOF && (N || M)) {
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				m[i][j] = 0;
		for (k = 0; k < 3; k++)
			for (i = 0; i < N; i++)
				for (j = 0; j < M; j++) {
					scanf("%d", &temp);
					m[i][j] += temp;
				}
		printf("Case %d:\n", t++);
		for (i = 0; i < N; i++) {
			for (j = 0; j < M - 1; j++)
				printf("%d,", m[i][j] / 3);
			printf("%d\n", m[i][j] / 3);
		}
	}
	return 0;
}
