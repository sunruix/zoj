#include <stdio.h>

int main()
{
	int a[5843], i, j, v[4], p[4][2];

	for (i = 0, v[0] = 2, v[1] = 3, v[2] = 5, v[3] = 7; i < 4; i++)
		p[i][0] = 1, p[i][1] = v[i];
	for (i = 2, a[1] = 1; i <= 5842; i++) {
		for (j = 0, a[i] = 0x7fffffff; j < 4; j++)
			if (p[j][1] < a[i])
				a[i] = p[j][1];
		for (j = 0; j < 4; j++)
			if (p[j][1] <= a[i])
				p[j][0]++, p[j][1] = v[j] * a[p[j][0]];
	}
	while (scanf("%d", &i) != EOF && i) {
		if (i % 10 == 1 && (i % 100) / 10 != 1)
			printf("The %dst ", i);
		else if (i % 10 == 2 && (i % 100) / 10 != 1)
			printf("The %dnd ", i);
		else if (i % 10 == 3 && (i % 100) / 10 != 1)
			printf("The %drd ", i);
		else
			printf("The %dth ", i);
		printf("humble number is %d.\n", a[i]);
	}
	return 0;
}