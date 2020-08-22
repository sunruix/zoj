#include <stdio.h>

int main()
{
	int n, price;

	while (scanf("%d", &n) != EOF && n) {
		for (price = 0; n >= 16; n -= 8)
			price += 18;
		if (n > 8 && n % 8 > 4) {
			price += 18;
			n -= 8;
		}
		if (n) {
			n -= 4;
			price += 10;
			if (n <= 0)
				printf("%d\n", price);
			else {
				n -= 4;
				if (n <= 0) {
					price += 2 * (n + 4);
					printf("%d\n", price);
				}
				else {
					if (n % 5)
						printf("%.1f\n", 2.4 * n + price + 8);
					else
						printf("%.0f\n", 2.4 * n + price + 8);
				}
			}
		}
	}
	return 0;
}