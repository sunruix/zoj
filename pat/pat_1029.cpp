#include <stdio.h>

long long a[1000000], b[1000000];

int main()
{
	int m, n, i, j, k, mid, ans;

	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%lld", &a[i]);
	scanf("%d", &n);
	for (j = 0; j < n; j++)
		scanf("%lld", &b[j]);
	mid = (m + n) % 2 ? (m + n) / 2 : (m + n) / 2 - 1;
	for (i = j = k = 0; i < m && j < n && k <= mid ; k++) {
		if (a[i] < b[j])
			ans = a[i++];
		else
			ans = b[j++];
	}
	if (k <= mid) {
		if (i < m) {
			for (; i < m && k <= mid; i++, k++);
			ans = a[i - 1];
		}
		else {
			for (; j < n && k <= mid; j++, k++);
			ans = b[j - 1];
		}
	}
	printf("%lld", ans);
	return 0;
}