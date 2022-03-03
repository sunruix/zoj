#include <stdio.h>

int main()
{
	int n, i, j;

	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &i, &j);
		if (i == j) {
			if (i % 2)
				printf("%d\n", 4 * (i / 2) + 1);
			else
				printf("%d\n", 4 * (i / 2));
		}
		else if (j == i - 2) {
			if (j % 2)
				printf("%d\n", 4 * (j / 2) + 3);
			else
				printf("%d\n", 4 * (j / 2) + 2);
		}
		else
			printf("No Number\n");
	}
	return 0;
}

