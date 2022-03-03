#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

char s[2000002][8];
int main()
{
	int n, i, j, m;

	while (scanf("%d\n", &n) != EOF) {
		for (i = 0, m = 2 * n - 1; i < m; i++) {
			for (j = 0; j < 8; j++)
				s[i][j] = getchar();
			s[i][7] = '\0';
		}
		qsort(s, m, sizeof(s[0]), comp);
		m--;
		for (i = 0; i < m; i += 2)
			if (strcmp(s[i], s[i + 1])) {
				printf("%s\n", s[i]);
				break;
			}
		if (i == m)
			printf("%s\n", s[i]);
	}
	return 0;
}
