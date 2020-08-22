#include <stdio.h>

int main()
{
	int n, a[64], sum, aver, i, count = 1;
	while (scanf("%d", &n) != EOF && n) {
		for (i = 0, sum = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		aver = sum / n;
		for (i = 0, sum = 0; i < n; i++)
			if (a[i] > aver)
				sum += a[i] - aver;
		printf("Set #%d\n", count++);
		printf("The minimum number of moves is %d.\n\n", sum);
	}
	return 0;
}
