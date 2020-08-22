#include <stdio.h>
#include <math.h>

int main()
{
	int b, n, a, i, sub1, sub2;
	freopen("input", "r", stdin);
	while (scanf("%d %d", &b, &n) != EOF && (b || n)) {
		sub2 = sub1 = b - 1;
		for (i = 2; sub2 > 0;i++) {
			sub1 = sub2;
			sub2 = b - (int)pow(i, n);
		}
		if (sub1 + sub2 > 0 || i == 2)
			printf("%d\n", i - 1);
		else
			printf("%d\n", i - 2);
	}
	return 0;
}
