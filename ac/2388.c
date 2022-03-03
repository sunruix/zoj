#include <stdio.h>

int main()
{
	int n, a, b, sum, sub;

	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &sum, &sub);
		if (sum < sub || (sum + sub) % 2 != 0) {
			printf("impossible\n");
			continue;
		}
		a = (sum + sub) / 2;
		b = sum - a;
		printf("%d %d\n", a, b);
	}
	return 0;
}
