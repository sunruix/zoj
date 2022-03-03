#include <stdio.h>
#include <string.h>

int main()
{
	int t, n, i, a[100001], ans, max;
	scanf("%d", &t);
	while (t--) {
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &i);
			a[i]++;
		}
		for (i = 1001, max = 0; i <= 9999; i++)
			if (max <= a[i]) {
				max = a[i];
				ans = i;
			}
		printf("%d\n", ans);
	}
	return 0;
}
