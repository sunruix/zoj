#include <stdio.h>
#include <string.h>

int m[512][512];

int main()
{
	int t, la, lb, i, j, k; 
	char a[512], b[512];

	scanf("%d", &t);
	while (t--) {
		scanf("%s %s", a + 1, b + 1), la = strlen(a + 1), lb = strlen(b + 1);
		for (i = 1; i <= la; i++)
			m[i][0] = -(4 + i);
		for (i = 1; i <= lb; i++)
			m[0][i] = -(4 + i);
		for (i = 1; i <= la; i++)
			for (j = 1; j <= lb; j++) {
				m[i][j] = m[i - 1][j - 1] + (a[i] == b[j] ? 2 : -1);
				for (k = 0; k < i; k++)
					m[i][j] < m[k][j] - (4 + i - k) ? m[i][j] = m[k][j] - (4 + i - k) : 0;
				for (k = 0; k < j; k++)
					m[i][j] < m[i][k] - (4 + j - k) ? m[i][j] = m[i][k] - (4 + j - k) : 0;
			}
		printf("%d\n", m[la][lb]);
	}
	return 0;
}
