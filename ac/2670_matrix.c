#include <stdio.h>

int main()
{
	int n, i, j, k;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n - 1; i++)
			printf("0 ");
		printf("0\n");
		for (i = 1; i < n; i++) {
			for (j = 0; j < i; j++)
				printf("0 ");
			for (; j < n - 1; j++)
				printf("1 ");
			printf("1\n");
		}
	}
	return 0;
}

