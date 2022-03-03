#include <stdio.h>

int main()
{
	int T, N, price, i, j, x, y, known, guess;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		price = known = 0;
		for (i = 0; i < 3; i++) {
			scanf("%d", &j);
			known = 10 * known + j;
		}
		known *= 10;
		for (i = 1; i <= 9; i++) {
			guess = 10000 * i + known;
			for (j = 0; j <= 9; j++) {
				if ((guess + j) % N == 0) {
					x = i, y = j;
					price = guess + j;
				}
			}
		}
		if (price)
			printf("%d %d %d\n", x, y, price / N);
		else
			printf("0\n");
	}
	return 0;
}
