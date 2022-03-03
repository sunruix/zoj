#include <stdio.h>

int main()
{
	int n, s, sum, max, min, i;
	while (scanf("%d", &n) != EOF && n) {
		max = sum = 0, min = 1000;
		for (i = 0; i < n; i++) {
			scanf("%d", &s);
			sum += s;
			if (s > max)
				max = s;
			if (s < min)
				min = s;
		}
		printf("%d\n", (sum - min - max) / (n - 2));
	}
	return 0;
}
