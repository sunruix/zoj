#include <stdio.h>

int main()
{
	int i, j, k, a, b[16];

	for (i = 0, j = -30; i < 12; b[i++] = (j += 30));
	while (scanf("%d", &a) != EOF && a >= 0) {
		for (i = 0; b[i] < a && i < 12; i++);
		if (b[i] == a)
			printf("Exactly %d o'clock\n", i > 3 ? 15 - i : 3 - i);
		else {
			if (i == 12)
				printf("Between 3 o'clock and 4 o'clock\n");
			else
				printf("Between %d o'clock and %d o'clock\n", i > 3 ? 15 - i : 3 - i, i - 1 > 3 ? 15 - i + 1 : 3 - i + 1);
		}
	}
	return 0;
}