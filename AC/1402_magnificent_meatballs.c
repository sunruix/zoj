#include <stdio.h>

int main()
{
	int n, a[32], i, sum, half;

	while (scanf("%d", &n) != EOF && n) {
		for (i = sum = 0; i < n; i++)
			scanf("%d", &a[i]), sum += a[i];
		if (sum % 2)
			printf("No equal partitioning.\n");
		else {
			for (i = half = 0, sum /= 2; i < n; i++) {
				half += a[i];
				if (half >= sum)
					break;
			}
			if (half > sum)
				printf("No equal partitioning.\n");
			else
				printf("Sam stops at position %d and Ella stops at position %d.\n", i + 1, i + 2);
		}
	}
	return 0;
}
