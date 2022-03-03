#include <stdio.h>

int main()
{
	int t, n, i, j, a[10001], m[10001], max, count;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			m[i] = 1;
		}
		for (i = n - 1, max = 1; i >= 1; i--)
			for (j = i - 1; j >= 0; j--)
				if (a[j] < a[i])
					if (m[j] < m[i] + 1) {
						m[j] = m[i] + 1;
						if (max < m[j])
							max = m[j];
					}
		printf("%d\n", max);
		if (t)
			printf("\n");
	}
	return 0;
}
