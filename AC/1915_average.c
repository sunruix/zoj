#include <stdio.h>

int main()
{
	int c, n, count, i, j, a[1024];
	double aver, per;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		for (i = 0, aver = 0; i < n; i++) {
			scanf("%d", &a[i]);
			aver += a[i];
		}
		aver /= n;
		for (i = 0, j = 0; i < n; i++)
			if (a[i] > aver)
				j++;
		per = (double)j / n * 100;
		printf("%.3f%%\n", per);
	}
	return 0;
}
