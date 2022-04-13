#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int a[1024], n, m, i, v = 0x7fffffff;

int main()
{
	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%d", &i);
		if (v != 1 && a[m - i] && min(i, m - i) < v)
			v = min(i, m - i);
		a[i] = 1;
	}
	if (v != 0x7fffffff)
		printf("%d %d\n", v, m - v);
	else
		printf("No Solution\n");
	return 0;
}