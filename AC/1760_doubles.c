#include <stdio.h>

int main()
{
	int array[16], i, j, k;
	int count;

	while (1)
	{
		count = 0;
		scanf("%d", &array[0]);
		if (array[0] == -1)
			break;
		for (i = 1; i < 16; i++)
		{
			scanf("%d", &array[i]);
			if (!array[i])
				break;
		}
		for (j = 0; j < i; j++)
			for (k = 0; k < i; k++)
				if (!(array[j] % array[k]) &&
						(array[j] / array[k] == 2))
				{
					count++;
					continue;
				}
		printf("%d\n", count);
	}
	return 0;
}
			
