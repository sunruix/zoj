#include <stdio.h>

int array[128], n;
void convert(int a, int b)
{
	int i = 0;
	if (a == 0) {
		array[0] = 0;
		n = 0;
		return;
	}
	while (a) {
		array[i++] = a % b;
		a /= b;
	}
	n = i - 1;
}

int check()
{
	int i, j;
	for (i = 0, j = n; i < j; i++, j--)
		if (array[i] != array[j])
			return 0;
	return 1;
}

int main()
{
	int a, b, i;
	scanf("%d %d", &a, &b);
	convert(a, b);
	if (check())
		printf("Yes\n");
	else
		printf("No\n");
	for (i = n; i > 0; i--)
		printf("%d ", array[i]);
	printf("%d\n", array[0]);
	return 0;
}
