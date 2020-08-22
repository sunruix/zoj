#include <stdio.h>

long long m[505][505];

int main()
{
	int n, i, j, k, l;

	for (j = 1; j <= 500; j++)
		for (i = 0; i + j <= 500; i++) {
			m[i][i + j] = 1;
			for (k = i + 1, l = j - 1; k < l; k++, l--)
				m[i][i + j] += m[k][l];
		}
	while (scanf("%d", &n) != EOF && n)
		printf("%Ld\n", m[0][n] - 1);
	return 0;
}