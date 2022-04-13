#include <stdio.h>

int main()
{
	int n, i, j;

	scanf("%d", &n);
	printf("%d=", n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	for (i = 2; i < n; i++) {
		if (!(n % i)) {
			j = 0;
			while (!(n % i))
				n /= i, j++;
			j > 1 ? printf("%d^%d", i, j) : printf("%d", i);
			if (n > 1)
				printf("*");
		}
	}
	if (n > 1)
		printf("%d\n", n);
	return 0;
}