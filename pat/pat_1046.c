#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
	int n, m, i, j, a[100002], ans;

	scanf("%d", &n);
	for (a[0] = a[1] = 0, i = 2; i <= n + 1; i++)
		scanf("%d", &a[i]), a[i] += a[i - 1];
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &i, &j);
		ans = i > j ? a[i] - a[j] : a[j] - a[i];
		printf("%d\n", min(ans, a[n + 1] - ans));
	}
	return 0;
}
