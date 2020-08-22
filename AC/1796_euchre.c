#include <stdio.h>

int main()
{
	int a, b, c[6], i, sub, sum, over;
	while (1) {
		for (i = 0, over = 1; i < 6; i++) {
			scanf("%d", &c[i]);
			if (c[i])
				over = 0;
		}
		if (over)
			return 0;
		sum = c[0] + c[1];
		sub = c[0] + c[2] + c[4] - c[1] - c[3] - c[5];
		b = (sum + sub) / 2;
		a = (sum - sub) / 2;
		printf("Anna's won-loss record is %d-%d.\n", a, b);
	}
	return 0;
}
