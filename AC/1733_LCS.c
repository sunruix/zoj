#include <stdio.h>
#include <string.h>

int main()
{
	int la, lb, i, j, record[1024][1024];
	char a[1024], b[1024];

	while (scanf("%s %s", a + 1, b + 1) != EOF) {
		la = strlen(a + 1), lb = strlen(b + 1);
		for (i = 0; i < 1024; i++)
			record[0][i] = record[i][0] = 0;
		for (i = 1; i <= la; i++) {
			for (j = 1; j <= lb; j++) {
				if (a[i] == b[j])
					record[i][j] = record[i - 1][j - 1] + 1;
				else if (record[i - 1][j] > record[i][j - 1])
					record[i][j] = record[i - 1][j];
				else
					record[i][j] = record[i][j - 1];
			}
		}
		printf("%d\n", record[la][lb]);
	}
	return 0;
}
