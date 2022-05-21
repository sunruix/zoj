#include <stdio.h>
#include <string.h>

int main()
{
	int n, a[256], b[10001], i, j, k, m, ans;

	memset(a, -1, sizeof(a)), b[0] = -1, ans = 0;
	scanf("%d", &n), scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &j), a[j] = i;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		if (a[k] > 0) {
			if (a[k] >= b[ans])
				b[++ans] = a[k];
			else {
				i = 1, j = ans;
				while (i < j) {
					m = (i + j) >> 1;
					b[m] > a[k] ? (j = m) : (i = m + 1);
				}
				b[i] = a[k];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
