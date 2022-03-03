#include <stdio.h>

int main()
{
	int n, a, b, i;

	while (scanf("%d", &n) != EOF && n) {
		for (b = i = 0; i < n; i++) {
			scanf("%d", &a);
			i + b < n - a ? b = n - a - i : 0;
		}
		printf("%d\n", b);
	}
	return 0;
}