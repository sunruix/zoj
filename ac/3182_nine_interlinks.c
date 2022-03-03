#include <stdio.h>

int main()
{
	int t, i, a[32];

	for (a[0] = 0, a[1] = 1, i = 2; i < 32; i++)
		a[i] = a[i - 1] + (a[i - 2] << 1) + 1;
	scanf("%d", &t);
	while (t--)
		scanf("%d", &i), printf("%d\n", a[i]);
	return 0;
}