#include <stdio.h>

int main()
{
	float input[101];
	int i = 0;

	while (1)
	{
		scanf("%f", &input[i]);
		if (input[i] == 999)
		{
			printf("End of Output\n");
			break;
		}
		if (i > 0)
			printf("%.2f\n", input[i] - input[i - 1]);
		i++;
	}
	return 0;
}
