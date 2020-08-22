#include <stdio.h>

int main()
{
	int i;
	float l, array[300];

	array[0] = 0;
	for (i = 1; i < 300; i++)
		array[i] = array[i - 1] + 1 / ((float)i + 1);
	while (scanf("%f", &l) != EOF && l >= 0.01) {
		for (i = 1;; i++)
			if (l <= array[i])
				break;
		printf("%d card(s)\n", i);
	}
	return 0;
}
