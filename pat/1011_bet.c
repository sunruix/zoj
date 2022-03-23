#include <stdio.h>

int main()
{
	int i, j;
	char map[3] = {'W', 'T', 'L'}, c[3];
	double info[3], g[3];

	for (i = 0; i < 3; i++) {
		scanf("%lf %lf %lf", &info[0], &info[1], &info[2]);
		g[i] = 0;
		for (j = 0; j < 3; j++) {
			if (info[j] > g[i]) {
				g[i] = info[j];
				c[i] = map[j];
			}
		}
	}
	printf("%c %c %c %.2lf\n", c[0], c[1], c[2], (g[0] * g[1] * g[2] * 0.65 - 1) * 2);
	return 0;
}
