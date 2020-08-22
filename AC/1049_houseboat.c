#include <stdio.h>

int main()
{
	int N, i, j;
	float x, y, d;
	const float pi = 3.1415927;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%f %f", &x, &y);
		d = x * x + y *y;
		for (j = 1;; j++)
			if (j * 100 / pi  > d)
				break;
		printf("Property %d: This property will begin eroding in year %d.\n", i, j);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
