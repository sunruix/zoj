#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, a[5000], inver[5000], min, ans;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		memset(inver, 0, sizeof(inver));
		for (i = min = 0; i < n; i++) {
			for (j = i + 1; j < n; j++)
				if (a[j] < a[i])
					inver[a[i]]++;
			min += inver[a[i]];
		}
		for (i = 0, ans = 0x7fffffff; i < n; i++) {
			for (j = a[i] + 1; j < n; j++)
				inver[j]++;
			min -= inver[a[i]] - (n - a[i] - 1);
			if (ans > min)
				ans = min;
		}
		printf("%d\n", ans);
	}
	return 0;
}