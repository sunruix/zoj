#include <stdio.h>

int main()
{
	int t, n, i, j, max, p[40960], m[40960];
	freopen("input2", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &p[i]);
			m[i] = 1;
		}
		for (i = n - 1, max = 1; i >= 1; i--)
			for (j = i - 1; j >= 0; j--)
				if (p[j] < p[i])
					if (m[j] < m[i] + 1) {
						m[j] = m[i] + 1;
						if (max < m[j])
							max = m[j];
					}
		printf("%d\n", max);
	}
	return 0;
}
