#include <stdio.h>

int main()
{
	int a, b, c, s, p, y, j, i;
	while (scanf("%d %d %d %d", &s, &p, &y, &j) != EOF) {
		i = 1;
		for (a = 0; i != 0; a++)
			for (b = 0; b <= a - s && i != 0; b++)
				for (c = 0; c <= a - y && c <= b - p && i != 0; c++)
					if (a + b + c == 12 + j) {
						i = 0;
						printf("%d %d %d\n", a, b, c);
					}
	}
	return 0;
}
