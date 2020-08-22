#include <stdio.h>
#include <string.h>

int m[1024][1024], n[1024][1024];

int main()
{
	int t, i, j, va[1024], vb[1024], la, lb, l, max;
	char sa[1024][16], sb[1024][16], s[16];

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &la);
		for (i = 1; i <= la; i++)
			scanf("%s %s %d", s, sa[i], &va[i]);
		scanf("%d", &lb);
		for (j = 1; j <= lb; j++)
			scanf("%s %s %d", s, sb[j], &vb[j]);
		memset(m, 0, sizeof(m));
		memset(n, 0, sizeof(n));
		for (i = 1, max = l = 0; i <= la; i++)
			for (j = 1; j <= lb; j++) {
				if (!strcmp(sa[i], sb[j])) {
					m[i][j] = m[i - 1][j - 1] + va[i] + vb[j];
					n[i][j] = n[i - 1][j - 1] + 1;
					if (m[i][j] < m[i - 1][j])
						m[i][j] = m[i - 1][j], n[i][j] = n[i - 1][j];
					if (m[i][j] < m[i][j - 1])
						m[i][j] = m[i][j - 1], n[i][j] = n[i][j - 1];
					if (max < m[i][j])
						max = m[i][j], l = n[i][j];
					else if (max == m[i][j] && l > n[i][j])
						l = n[i][j];
				}
				else if (m[i - 1][j] > m[i][j - 1])
					m[i][j] = m[i - 1][j], n[i][j] = n[i - 1][j];
				else if (m[i - 1][j] < m[i][j - 1])
					m[i][j] = m[i][j - 1], n[i][j] = n[i][j - 1];
				else {
					m[i][j] = m[i][j - 1];
					n[i][j] = n[i - 1][j] < n[i][j - 1] ? n[i - 1][j] : n[i][j - 1];
				}
			}
		printf("%d %d\n", max, l);
	}
	return 0;
}