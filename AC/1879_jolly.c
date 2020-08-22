#include <stdio.h>

int main()
{
	int n, i, a[4096], b[4096], diff;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if (n <= 1) {
			printf("Jolly\n");
			continue;
		}
		for (i = 1; i < n; i++)
			b[i] = 0;
		for (i = 0; i < n - 1; i++) {
			diff  = a[i] > a[i + 1] ? a[i] - a[i + 1] : a[i + 1] - a[i];
			if (diff == 0 || diff >= n || b[diff]) {
				printf("Not jolly\n");
				break;
			}
			b[diff] = 1;
		}
		if (i == n - 1)
			printf("Jolly\n");
	}
	return 0;
}
