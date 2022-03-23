#include <stdio.h>

int main()
{
	int n, m, k, a[1001], i, j, l, pre, cap, ans;

	scanf("%d %d %d", &m, &n, &k);
	while (k--) {
		for (cap = m, ans = 1, pre = i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (i && a[i] < a[i - 1])
				cap++;
			else
				cap = cap - (a[i] - pre) + 1;
			if (cap <= 0 || cap > m)
				ans = 0;
			if (pre < a[i])
				pre = a[i];
		}
		for (i = 0; i < n && ans; i++) {
			for (j = i + 1; j < n && a[j] > a[i]; j++);
			for (l = j + 1; l < n && !(a[l] > a[j] && a[l] < a[i]); l++);
			if (l < n)
				ans = 0;
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}
