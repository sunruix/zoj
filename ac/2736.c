#include <stdio.h>

int main()
{
	int i1, i2, i3;
	char c[4];

	while (scanf("%s", c) != EOF) {
		i1 = c[0] - '0', i2 = c[1] - '0', i3 = c[2] - '0';
		if (100 * i1 + 10 * i2 + i3 == i1 * i1 * i1 + i2 * i2 * i2 + i3 * i3 * i3)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
