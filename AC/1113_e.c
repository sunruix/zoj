#include <stdio.h>

int main()
{
	int i, lad[10];
	double res, temp;

	lad[0] = 1;
	for (i = 1; i < 10; i++)
		lad[i] = i * lad[i - 1];

	printf("n e\n");
	printf("- -----------\n");
	for (i = 0; i < 2; i++)
		printf("%d %d\n", i, i + 1);
	printf("%d 2.5\n", i++);
	for (res = 2.5; i < 10; i++) {
		temp = (double)1 / lad[i];
		res += temp;
		printf("%d %.9f\n", i, res);
	}
	return 0;
}

