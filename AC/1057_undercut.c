#include <stdio.h>

int main()
{
	int n, a[128], b[128], aa, bb, i, count = 0;
	freopen("input", "r", stdin);
	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &b[i]);
		for (i = 0, aa = bb = 0; i < n; i++) {
			if (a[i] == b[i]);
			else if (abs(a[i] - b[i]) > 1) {
				if (a[i] > b[i])
					aa += a[i];
				else
					bb += b[i];
			}
			else if (a[i] == 1 || b[i] == 1) {
				if (a[i] == 1)
					aa += 6;
				else
					bb += 6;
			}
			else {
				if (a[i] < b[i])
					aa += a[i] + b[i];
				else
					bb += a[i] + b[i];
			}
		}
		if (count++)
			printf("\n");
		printf("A has %d points. B has %d points.\n", aa, bb);
	}
	return 0;
}
