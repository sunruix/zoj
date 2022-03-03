#include <stdio.h>

int main()
{
	float sum = 0, average;
	long long intaver;
	int i;
	for (i = 0; i < 12; i++) {
		scanf("%f", &average);
		sum += average;
	}
	intaver = (int)(sum * 1000);
	intaver /= 12;
	if (intaver % 10 < 5)
		intaver /= 10;
	else
		intaver = (intaver + 10) / 10;
	average = (double)(intaver) / 100;
	printf("$%.2f\n", average);
	return 0;
}
