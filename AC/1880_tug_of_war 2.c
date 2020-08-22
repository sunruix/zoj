#include <stdio.h>
#include <string.h>

/**
int main()
{
	int n, i, j, a[128], m[512 * 128], sum, sub, min, ans;
	freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		memset(m, 0, sizeof(m));
		for (i = 1, sum = 0; i <= n; i++)
			scanf("%d", &a[i]), sum += a[i];
		for (m[0] = i = 1; i <= n; i++)
			for (j = sum; j >= a[i]; j--)
				m[j] = m[j] || m[j - a[i]];
		for (i = 1, min = 0x7fffffff; i <= sum; i++)
			if (m[i]) {
				sub = sum - 2 * i > 0 ? sum - 2 * i : 2 * i - sum;
				if (sub < min)
					min = sub, ans = i;
			}
		if (ans < sum - ans)
			printf("%d %d\n", ans, sum - ans);
		else
			printf("%d %d\n", sum - ans, ans);
	}
	return 0;
}
**/