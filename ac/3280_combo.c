#include <stdio.h>

int main()
{
	int n, m, i, j, k, v[50001][8], w[8], max, min, limit, temp, ans;
	freopen("input1", "r", stdin);
	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &v[i][j]);
		for (i = 0; i < m; i++)
			scanf("%d", &w[i]);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				v[i][j] *= w[j];
		limit = 1 << m;
		for (i = 0, ans = 0; i < limit; i++) {
			max = -0x7fffffff, min = 0x7fffffff;
			for (j = 0; j < n; j++) {
				temp = 0;
				for (k = 0; k < m; k++) {
					if (i & (1 << k))
						temp += v[j][k];
					else
						temp -= v[j][k];
				}
				if (max < temp)
					max = temp;
				if (min > temp)
					min = temp;
			}
			if (ans < max - min)
				ans = max - min;
		}
		printf("%d\n", ans);
	}
	return 0;
}
