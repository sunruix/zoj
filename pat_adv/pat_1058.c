#include <stdio.h>

int i, a[4], b[4];

int main()
{
	scanf("%d.%d.%d %d.%d.%d", &a[1], &a[2], &a[3], &b[1], &b[2], &b[3]);
	a[3] += b[3], a[2] += b[2], a[1] += b[1];
	if (a[3] >= 29)
		a[3] -= 29, a[2]++;
	if (a[2] >= 17)
		a[2] -= 17, a[1]++;
	for (i = 1; i < 4; i++)
		printf("%d%c", a[i], i == 3 ? '\n' : '.');
	return 0;
}