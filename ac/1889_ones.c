#include <stdio.h>

int main()
{
	int m, n, i;
	while (scanf("%d", &n) != EOF) {
		for (i = 0, m = 1; (m %= n); i++, m = 10 * m + 1);
			printf("%d\n", i + 1);
	}
	return 0;
}
