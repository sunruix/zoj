#include <stdio.h>

int main()
{
	int n, T, a0, a1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		a0 = n % 10;
		a1 = (n / 10) % 10;
		if (a1 == 1) {
			printf("%dth\n", n);
			continue;
		}
		printf("%d", n);
		switch (a0) {
			case 1:
				printf("st\n");
				break;
			case 2:
				printf("nd\n");
				break;
			case 3:
				printf("rd\n");
				break;
			default:
				printf("th\n");
		}
	}
	return 0;
}
