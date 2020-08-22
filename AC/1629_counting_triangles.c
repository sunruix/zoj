#include <stdio.h>

int main()
{
	int i, a[512];

	for (a[1] = 1, i = 2; i <= 500; i++)
		a[i] = a[i - 1] + i * (i + 1) / 2 + (i % 2 ? (i >> 1) * (i / 2 + 1) : (i * i >> 2));
	while (scanf("%d", &i) != EOF)
		printf("%d\n", a[i]);
	return 0;
}