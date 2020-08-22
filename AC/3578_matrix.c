#include <stdio.h>

int main()
{
	int n, m, c, h, a[1024][8], i, j, max;

	while (scanf("%d %d %d", &n, &m, &c) != EOF) {
		for (max = i = 0; i < c; i++) {
			scanf("%d %d %d %d %d", &a[i][3], &a[i][4], &h, &a[i][1], &a[i][2]);
			a[i][3] += a[i][1] - 1, a[i][4] += a[i][2] - 1, a[i][0] = h;
			for (j = 0; j < i; j++) {
				if (!(a[i][1] > a[j][3] || a[i][3] < a[j][1] ||
					a[i][2] > a[j][4] || a[i][4] < a[j][2]))
					if (a[i][0] < a[j][0] + h)
						a[i][0] = a[j][0] + h;
			}
			if (max < a[i][0])
				max = a[i][0];
		}
		printf("%d\n", max);
	}
	return 0;
}