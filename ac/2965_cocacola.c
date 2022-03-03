#include <stdio.h>

int check(int n)
{
	if (n % 7 == 0)
		return 1;
	while (n) {
		if (n % 10 == 7)
			return 1;
		n /= 10;
	}
	return 0;
}

int main()
{
	int t, p, count, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &p);
		if (p > 20) {
			printf("700\n");
				continue;
		}
		for (i = 1, count = 0;;i++) {
			if (check(i)) {
				count++;
				if (count == p) {
					printf("%d\n", i - p + 1);
					break;
				}
			}
			else
				count = 0;
		}
	}
	return 0;
}
