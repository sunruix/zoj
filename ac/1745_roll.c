#include <stdio.h>

int main()
{
	int target, loc, locc, pre, cur, count = 0;

	while (scanf("%d", &target) != EOF && target != 5280) {
		if (count++)
			printf("\n");
		locc = 0;
		while (scanf("%d", &loc) != EOF && loc != target) {
			if (abs(loc - target) > abs(locc - target))
				printf("Moving from %d to %d: colder.\n", locc, loc);
			else if (abs(loc - target) < abs(locc - target))
				printf("Moving from %d to %d: warmer.\n", locc, loc);
			else
				printf("Moving from %d to %d: same.\n", locc, loc);
			locc = loc;
		}
		printf("Moving from %d to %d: found it!\n", locc, loc);
	}
	return 0;
}

