#include <stdio.h>

int main()
{
	int n, sum, i, j;

	printf("PERFECTION OUTPUT\n");
	while (scanf("%d", &n) != EOF && n) {
		for (i = 2, sum = 0, j = n / 2; i <= j; i++)
			if (n % i == 0)
				sum += i;
		printf("%5d  ", n);
		if (++sum > n)
			printf("ABUNDANT\n");
		else if (sum < n || n == 1)
			printf("DEFICIENT\n");
		else
			printf("PERFECT\n");	
	}
	printf("END OF OUTPUT\n");
	return 0;
}