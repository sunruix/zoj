#include <stdio.h>

int main()
{
	int n;

	while (scanf("%d", &n) != EOF)
		printf("%d\n", 9 * (n - 1) * n / 2 + (n - 1) + 2);
	return 0;
}