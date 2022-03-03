#include <stdio.h>

int main()
{
	int n, i, speed, hour, pre, sum;

	while (scanf("%d", &n) != EOF && n > 0) {
		pre = sum = 0;
		for (i = 0; i < n; i++) {
			scanf("%d %d", &speed, &hour);
			sum += speed * (hour - pre);
			pre = hour;
		}
		printf("%d miles\n", sum);
	}
	return 0;
}
