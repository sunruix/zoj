#include <stdio.h>

int max(int a, int b, int c)
{
	a = a > b ? a : b;
	return a > c ? a : c;
}

int score[5][5] = {5, -1, -2, -1, -3,
	-1, 5, -3, -2, -4,
	-2, -3, 5, -2, -2,
	-1, -2, -2, 5, -1,
	-3, -4, -2, -1, 0};

int main()
{
	int t, map[128], i, j, la, lb, m[128][128];
	char a[128], b[128];

	map['A'] = 0, map['C'] = 1, map['G'] = 2, map['T'] = 3;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %s", &la, a + 1);
		scanf("%d %s", &lb, b + 1);
		m[0][0] = 0;
		for (i = 1; i <= la; i++)
			m[i][0] = score[map[a[i]]][4] + m[i - 1][0];
		for (j = 1; j <= lb; j++)
			m[0][j] = score[4][map[b[j]]] + m[0][j - 1];
		for (i = 1; i <= la; i++) {
			for (j = 1; j <= lb; j++) {
				m[i][j] = max(m[i - 1][j - 1] + score[map[a[i]]][map[b[j]]],
					m[i - 1][j] + score[map[a[i]]][4],
					m[i][j - 1] + score[4][map[b[j]]]);
			}
		}
		printf("%d\n", m[la][lb]);
	}
	return 0;
}

