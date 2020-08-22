#include <stdio.h>

int main()
{
	int n, i, a[1024], b[1024], c[1024], borrow, ans;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &b[i]);
		for (i = n - 1, borrow = 0; i >= 0; i--) {
			if (a[i] + borrow > b[i]) {
				borrow = a[i] + borrow - b[i];
				c[i] = b[i];
			}
			else {
				c[i] = a[i] + borrow;
				borrow = 0;
			}
		}
		if (borrow)
			printf("Myon\n");
		else {
			for (i = 0; i < n - 1; i++)
				printf("%d ", c[i]);
			printf("%d\n", c[i]);
		}
	}
	return 0;
}
