#include <stdio.h>

int main()
{
	double table[4] = {2.2046, 0.4536, 0.2642, 3.7854}, a, b;
	int N, i;
	char s[4];
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%lf %s", &a, s);
		printf("%d ", i);
		if (s[0] == 'k' && s[1] == 'g')
			printf("%.4f lb\n", table[0] * a);
		else if (s[0] == 'l' && s[1] == 'b')
			printf("%.4f kg\n", table[1] * a);
		else if (s[0] == 'l')
			printf("%.4f g\n", table[2] * a);
		else
			printf("%.4f l\n", table[3] * a);
	}
	return 0;
}
