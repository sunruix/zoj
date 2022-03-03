#include <stdio.h>

int main()
{
	int s, d, i;

	while (scanf("%d %d", &s, &d) != EOF && (s || d)) {
		for (i = 1; i <= 60 && (s = (d + 1) * s % 60); i++);
		if (i > 60)
			printf("Impossible\n");
		else
			printf("%d\n", i);
	}
	return 0;
}