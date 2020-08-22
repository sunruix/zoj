#include <stdio.h>

int main()
{
	int d, n, i;
	scanf("%d", &d);
	while (d--) {
		scanf("%d", &n);
		for (i = 0; n != 1; i++, n = n >> 1)
			if (n & 1)
				printf("%d ", i);
		printf("%d\n", i);
	}
	return 0;
}
