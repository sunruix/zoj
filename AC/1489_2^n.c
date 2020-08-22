#include <stdio.h>

int main()
{
	int n, k, i;

	while (scanf("%d", &n) != EOF) {
		if (!(n % 2) || n == 1)
			printf("2^? mod %d = 1\n", n);
		else {
			i = 1, k = 2;
			while ((k = k % n) != 1)
				k <<= 1, i++;
			printf("2^%d mod %d = 1\n", i, n);
		}
	}
	return 0;
}