#include <stdio.h>

float rnd(float f)
{
	int i;
	f *= 100;
	i = (int)f;
	if (f - i >= 0.5)
		i += 1;
	return (float)i / 100;
}

int main()
{
	int N, m, i, j, p, temp;
	float money, array[6][6], path[10];

	scanf("%d", &N);
	while (N--) {
		for (i = 1; i <= 5; i++)
			for (j = 1; j <= 5; j++)
				scanf("%f", &array[i][j]);
		while (scanf("%d", &m) && m) {
			j = 1;
			for (i = 0; i < m; i++) {
				scanf("%d", &p);
				path[i] = array[j][p];
				j = p;
			}
			path[i] = array[j][1];
			scanf("%f", &money);
			for (i = 0; i <= m; i++) {
				money *= path[i];
				money = rnd(money);
			}
			printf("%.2f\n", money);
		}
		if (N)
			printf("\n");
	}
	return 0;
}
