#include <stdio.h>
#include <string.h>

int main()
{
	int t, n, i, j, k, la, lb, m[256][256];
	char a[256], b[256], c[512];

	scanf("%d", &t);
	for (n = 1; n <= t; n++) {
		scanf("%s %s %s", a + 1, b + 1, c + 1);
		la = strlen(a + 1), lb = strlen(b + 1);
		memset(m, 0, sizeof(m));
		for (i = 1; i <= la && a[i] == c[i]; i++)
			m[i][0] = 1;
		for (i = 1; i <= lb && b[i] == c[i]; i++)
			m[0][i] = 1;
		for (i = 1; i <= la; i++)
			for (j = 1; j <= lb; j++) {
				k = i + j;
				if (a[i] == c[k] && b[j] == c[k])
					m[i][j] = (m[i - 1][j] || m[i][j - 1]);
				else if (a[i] == c[k])
					m[i][j] = m[i - 1][j];
				else if (b[j] == c[k])
					m[i][j] = m[i][j - 1];
			}
		printf("Data set %d: ", n);
		if (m[la][lb])
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
