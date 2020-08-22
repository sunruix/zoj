#include <stdio.h>
#include <string.h>

int main()
{
	int n, m, i, j, k, over;
	char a[16][16], b[16][16];

	while (scanf("%d %d %d\n", &n, &m, &j) != EOF && n) {
		for (i = 0; i < n; i++)
			scanf("%s", a[i]);
		memset(b, 0, sizeof(b));
		i = 0, j--, over = k = 0;
		while (!over) {
			b[i][j] = ++k;
			switch (a[i][j]) {
			case 'N': i--; break;
			case 'S': i++; break;
			case 'E': j++; break;
			case 'W': j--; break;
			}
			if (i < 0 || i >= n || j < 0 || j >= m)
				printf("%d step(s) to exit\n", k), over = 1;
			else if (b[i][j])
				printf("%d step(s) before a loop of %d step(s)\n", b[i][j] - 1, k - b[i][j] + 1), over = 1;
		}
	}
	return 0;
}
