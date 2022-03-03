#include <stdio.h>

int main()
{
	int p, s, count = 1;
	
	while (scanf("%d %d", &p, &s) != EOF && (p || s)) {
		printf("Hole #%d\n", count++);
		if (s == p)
			printf("Par.\n");
		else if (s == 1)
			printf("Hole-in-one.\n");
		else if (s == p - 1)
			printf("Birdie.\n");
		else if (s == p - 2)
			printf("Eagle.\n");
		else if (s == p - 3)
			printf("Double Eagle.\n");
		else if (s == p + 1)
			printf("Bogey.\n");
		else if (s >= p + 2)
			printf("Double Bogey.\n");
		printf("\n");
	}
	return 0;
}
