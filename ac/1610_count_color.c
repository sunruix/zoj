#include <stdio.h>
#include <string.h>

int main()
{
	int n, x1, x2, c, m[10000], r[10000], i, j, left, right, maxc;
	freopen("input1", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		left = 0x7fffffff, right = 0, maxc = 0;
		memset(r, 0, sizeof(r));
		memset(m, -1, sizeof(m));
		for (i = 0; i < n; i++) {
			scanf("%d %d %d", &x1, &x2, &c);
			for (j = x1; j < x2; j++)
				m[j] = c;
			if (maxc < c)
				maxc = c;
			if (x1 < left)
				left = x1;
			if (x2 > right)
				right = x2;
		}
		c = -1;
		for (i = left; i < right; i++)
			if (m[i] != c) {
				if (m[i] >= 0)
					r[m[i]]++;
				c = m[i];
			}
		for (i = 0; i <= maxc; i++)
			if (r[i])
				printf("%d %d\n", i, r[i]);
		printf("\n");
	}
	return 0;
}

