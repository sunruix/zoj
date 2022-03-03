#include <stdio.h>
#include <string.h>

int main()
{
	int t, inv, y, n, a[16], v[16], m[50000], i, j, k, max;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &inv, &y, &n);
		for (i = 0; i < n; i++)
			scanf("%d %d", &a[i], &v[i]), a[i] /= 1000;
		while (y--) {
			memset(m, 0, sizeof(m)), max = 0, k = inv / 1000;
			for (i = 0; i < n; i++)
				for (j = a[i]; j <= k; j++) {
					m[j - a[i]] + v[i] > m[j] ? m[j] = m[j - a[i]] + v[i] : 0;
					max < m[j] ? max = m[j] : 0;
				}
			inv += max;
		}
		printf("%d\n", inv);
	}
	return 0;
}