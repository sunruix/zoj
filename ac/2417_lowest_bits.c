#include <stdio.h>

int main ()
{
	int A, i, j;

	while (scanf("%d", &A) != EOF && A) {
		i = 1;
		while (!(A % 2)) {
			i *= 2;
			A /= 2;
		}
		printf("%d\n", i);
	}
	return 0;
}
