#include <stdio.h>
#include <string.h>

int main()
{
	int cap, N, n, d, i, j, a[128], m[100001], ans;

	while (scanf("%d", &cap) != EOF) {
		scanf("%d", &N), j = ans = 0, memset(m, 0, sizeof(m));
		while (N--) {
			scanf("%d %d", &n, &d);
			for (i = 1; n > i - 1; i <<= 1);
			for (i >>= 2; n > i && i; i >>= 1)
				a[j++] = d * i, n -= i;
			n ? a[j++] = d * n: 0;
		}
		if (cap) {
			for (n = j, i = 0; i < n; i++)
				for (j = cap; j >= a[i]; j--) {
					m[j] = m[j - a[i]] + a[i] > m[j] ? m[j - a[i]] + a[i] : m[j];
					ans < m[j] ? ans = m[j] : 0;
				}
			printf("%d\n", ans);
		}
		else
			printf("0\n");
	}
	return 0;
}