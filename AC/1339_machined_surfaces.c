#include <stdio.h>

int main()
{
	int n, c, i, j, a[16], ans, min;

	while (scanf("%d\n", &n) != EOF && n) {
		for (min = 32, i = 0; i < n; i++) {
			for (a[i] = j = 0; j < 26; j++)
				(c = getchar()) == ' ' ? a[i]++ : 0;
			min > a[i] ? min = a[i] : 0;
		}
		for (ans = i = 0; i < n; i++)
			ans += a[i] - min;
		printf("%d\n", ans);
	}
	return 0;
}