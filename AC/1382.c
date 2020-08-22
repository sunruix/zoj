#include <stdio.h>

int main()
{
	int d, n, i;
	scanf("%d", &d);
	while (d--) {
		scanf("%d", &n);
		for (i = 0; !(n & 1); i++, n >>= 1);
		printf("%d %d\n", n, i);
	}
	return 0;
}
