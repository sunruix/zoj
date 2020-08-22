#include <stdio.h>

int main()
{
	int n, s, t, i, m, l, r, mid, pos, a[100000], ans;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &s);
		for (scanf("%d", &a[0]), i = 1; i < n; i++)
			scanf("%d", &a[i]), a[i] += a[i - 1];
		for (i = 0; i < n && a[i] < s; i++);
		ans = i < n ? i + 1 : 0;
		if (ans && ans != 1) {
			for (; i < n; i++) {
				m = a[i] - s, l = 0, r = i - 1, pos = -1;
				while (l < r) {
					mid = (l + r) / 2;
					if (a[mid] == m) {
						pos = mid + 1;
						break;
					}
					a[mid] < m ? (l = mid + 1) : (r = mid - 1);
				}
				pos = pos > 0 ? pos : (a[r] > m ? r : l);
				if (ans > i - pos + 1)
					ans = i - pos + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
