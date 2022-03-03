#include <stdio.h>

int main()
{
	int n, i, j, a[1024], ans;

	while (scanf("%d", &n) != EOF && n) {
		while (scanf("%d", &a[0]) != EOF && a[0]) {
			for (ans = i = 1; i < n; i++) {
				scanf("%d", &a[i]);
				if (ans && a[i] > a[i - 1]) {
					for (j = 0; j < i - 1 && a[j] < a[i]; j++);
					j == i - 1 ? 0 : (ans = 0);
				}
			}
			printf("%s\n", ans ? "Yes" : "No");
		}
		printf("\n");
	}
	return 0;
}