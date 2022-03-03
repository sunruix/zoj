#include <stdio.h>
#include <string.h>

int main()
{
	int n, d, i, j, row[128], col[128], pr, pc, er, ec;

	while (scanf("%d", &n) != EOF && n) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &d);
				row[i] += d, col[j] += d;
			}
		}
		for (i = 0, er = ec = 0; i < n; i++) {
			if (row[i] % 2)
				er++, pr = i;
			if (col[i] % 2)
				ec++, pc = i;
		}
		if (!er && !ec)
			printf("OK\n");
		else if (er == 1 && ec == 1)
			printf("Change bit (%d,%d)\n", pr + 1, pc + 1);
		else
			printf("Corrupt\n");
	}
	return 0;
}
